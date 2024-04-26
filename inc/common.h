#ifndef COMMON_H_
#define COMMON_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "uart.h"
#include "serviceLed.h"
#include "twi.h"
#include "pcaShield.h"

uint8_t digit(uint16_t d, uint8_t m);

#endif