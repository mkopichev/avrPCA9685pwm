#ifndef PCASHIELD_H_
#define PCASHIELD_H_

#include "common.h"

#define PCA_ADDRESS  0x40
#define MODE1        0x00
#define MODE2        0x01
#define LED0_ON_L    0x06
#define LED0_ON_H    0x07
#define LED0_OFF_L   0x08
#define LED0_OFF_H   0x09
#define CHANNEL_STEP 4
#define PRE_SCALE    0xFE

void pwmInit(uint16_t pwmFrequency);                        // frequency in Hz
void pwmDutyCycle(uint8_t channelNumber, uint16_t pulseUs); // channel number and length of logic high in us

#endif