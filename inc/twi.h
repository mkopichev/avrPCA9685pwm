#ifndef TWI_H_
#define TWI_H_

#include "common.h"

#define W 0
#define R 1

#define SCL_FREQ 200 // kHz

void twiInit(void);
void twiStart(void);
void twiStop(void);
void twiTransmitByte(uint8_t data);
uint8_t twiReceiveByte(bool isLastByte);
void twiWriteData(uint8_t *txBuf, uint8_t length);
void twiReadData(uint8_t *rxBuf, uint8_t length);

#endif