#include "../inc/serviceLed.h"

void serviceLedInit(void) {

    DDRB |= (1 << 5);
    TCCR0B = (1 << CS01); // prescaler 8
    TIMSK0 = (1 << TOIE0);
    sei();
}

ISR(TIMER0_OVF_vect) { // 128 us ovf period

    static uint16_t t0_counter = 0;

    if(t0_counter < ((LED_FLASHING_PERIOD * 1000000.0) / 128.0)) {
        t0_counter++;
    } else {
        t0_counter = 0;
        PORTB ^= (1 << 5);
    }
}