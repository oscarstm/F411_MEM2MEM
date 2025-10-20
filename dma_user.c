/*
 * dma_user.c
 *
 *  Created on: Oct 19, 2025
 *      Author: oscar
 */

#include "dma_user.h"

void dma_config(void) {
	RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;

	DMA2_Stream7->CR = 0;

	while (DMA2_Stream7->CR & DMA_SxCR_EN) {
		//
	}
	// 16 bit == 2 B
	DMA2_Stream7->CR |= DMA_SxCR_MSIZE_0;
	DMA2_Stream7->CR &= ~DMA_SxCR_MSIZE_1;

	DMA2_Stream7->CR |= DMA_SxCR_PSIZE_0;
	DMA2_Stream7->CR &= ~DMA_SxCR_PSIZE_1;
	DMA2_Stream7->CR |= DMA_SxCR_MINC;
	DMA2_Stream7->CR |= DMA_SxCR_PINC;
	DMA2_Stream7->CR &= ~DMA_SxCR_DIR_0;
	DMA2_Stream7->CR |= DMA_SxCR_DIR_1;
	DMA2_Stream7->CR |= DMA_SxCR_TCIE;
	DMA2_Stream7->CR |= DMA_SxCR_TEIE;
	DMA2_Stream7->FCR |= DMA_SxFCR_DMDIS;
	DMA2_Stream7->FCR |= DMA_SxFCR_FTH_0;
	DMA2_Stream7->FCR |= DMA_SxFCR_FTH_1;

	NVIC_EnableIRQ(DMA2_Stream7_IRQn);
}

void dma_start(uint32_t src_buff, uint32_t dst_buff, uint32_t len) {
	DMA2_Stream7->PAR = src_buff;
	DMA2_Stream7->M0AR = dst_buff;
	DMA2_Stream7->NDTR = len;

	DMA2_Stream7->CR |= DMA_SxCR_EN;
}
