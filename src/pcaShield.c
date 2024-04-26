#include "../inc/pcaShield.h"

float periodUs = 0;

void pcaSetRegister(uint8_t registerAddress, uint8_t registerValue) {

    twiStart();
    twiTransmitByte((PCA_ADDRESS << 1) | W);
    twiTransmitByte(registerAddress);
    twiTransmitByte(registerValue);
    twiStop();
}

void pcaSetMultipleRegister(uint8_t registerAddress, uint8_t *registerValue, uint8_t bufferSize) {

    twiStart();
    twiTransmitByte((PCA_ADDRESS << 1) | W);
    twiTransmitByte(registerAddress);
    twiWriteData(registerValue, bufferSize);
    twiStop();
}

uint8_t pcaGetRegister(uint8_t registerAddress) {

    uint8_t result = 0;
    twiStart();
    twiTransmitByte((PCA_ADDRESS << 1) | W);
    twiTransmitByte(registerAddress);
    twiStart();
    twiTransmitByte((PCA_ADDRESS << 1) | R);
    result = twiReceiveByte(true);
    twiStop();
    return result;
}

void pwmInit(uint16_t pwmFrequency) {

    uint8_t prescaleValue = lround((25000000.0 / 4096.0 / ((float)pwmFrequency)) - 0.5);
    pcaSetRegister(MODE1, (1 << 4)); // sleep ON
    pcaSetRegister(PRE_SCALE, prescaleValue);
    pcaSetRegister(MODE1, (1 << 7)); // restart ON

    periodUs = (1.0 / pwmFrequency) * 1000000.0;
}

void pwmDutyCycle(uint8_t channelNumber, uint16_t pulseUs) {

    uint8_t buffer[] = {0, 0, 0, 0}; // led-on: low high; led-off: low high

    pcaSetRegister(MODE1, pcaGetRegister(MODE1) | (1 << 5)); // auto-increment ON

    buffer[2] = ((uint16_t)(4096.0 / (periodUs / pulseUs))) & 0xFF;
    buffer[3] = ((uint16_t)(4096.0 / (periodUs / pulseUs))) >> 8;

    pcaSetMultipleRegister(LED0_ON_L + (CHANNEL_STEP * channelNumber), buffer, 4);
}