#include "inc/common.h"

void initAll(void);

int main(void) {

    initAll();

    while(1) {

        for(uint16_t i = 900; i <= 2100; i++) {
            pwmDutyCycle(1, i); // argument 1 - channel number, argument 2 - pulse width in us
            _delay_ms(2);
        }
        for(uint16_t i = 2100; i >= 900; i--) {
            pwmDutyCycle(1, i);
            _delay_ms(2);
        }
    }
}

void initAll() {

    serviceLedInit();
    uartInit();
    twiInit();
    pwmInit(333);
    _delay_ms(100);
}