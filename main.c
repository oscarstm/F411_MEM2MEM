#include <stdio.h>
#include <string.h>
#include "clk_user.h"
#include "dma_user.h"

#define BUFFER_SIZE 2

uint16_t data[BUFFER_SIZE] = { 892, 46 };
uint16_t copy_data[BUFFER_SIZE];

volatile uint8_t transfer;

int main(void) {
	transfer = 0;

	clk_user_init();
	dma_config();

	dma_start((uint32_t) data, (uint32_t) copy_data, BUFFER_SIZE);

	while (!transfer) {
		//
	}
	for (int i = 0; i < BUFFER_SIZE; ++i) {
		printf("Temp index[%d]: %d\r\n", i, copy_data[i]);
	}
	transfer = 0;

	while (1) {

	}

}

void DMA2_Stream7_IRQHandler(void) {
	if ((DMA2->HIFCR) & DMA_HIFCR_CTCIF7) {
		transfer = 1;
		DMA2->HIFCR |= DMA_HIFCR_CTCIF7;
	}

	if ((DMA2->HISR) & DMA_HISR_TEIF7) {
		DMA2->HIFCR |= DMA_HIFCR_CTEIF7;
	}
}
