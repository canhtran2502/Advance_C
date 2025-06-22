#include "actuators.h"
#include "config.h"
#include <stdio.h>

PumpState pump_state;
LEDState led_state; 

// Function to turn the water pump on
void turn_pump_on() {
    pump_state = PUMP_ON; // Set pump state to ON
    printf("Water pump is ON\n");
}

// Function to turn the water pump off
void turn_pump_off() {
    pump_state = PUMP_OFF; // Set pump state to OFF
    printf("Water pump is OFF\n");
}

// Function to update the LED status based on system state
void update_led_status() {
    switch (led_state) {
        case LED_NORMAL:
            printf("LED: Normal\n");
            break;
        case LED_WATERING:
            printf("LED: Watering\n");
            break;
        case LED_LOW_MOISTURE_ALERT:
            printf("LED: Low moisture alert\n");
            break;
        case LED_ERROR:
            printf("LED: System error\n");
            break;
    }
}
