/*
 * dma_user.h
 *
 *  Created on: Oct 19, 2025
 *      Author: oscar
 */

#ifndef DMA_USER_H_
#define DMA_USER_H_

#include "stm32f4xx.h"

void dma_config(void);
void dma_start(uint32_t src_buff, uint32_t dst_buff, uint32_t len);

#endif /* DMA_USER_H_ */
