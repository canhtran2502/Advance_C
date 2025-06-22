#include "watering_logic.h"
#include "config.h"
#include "actuators.h"
#include "sensors.h"
#include <stdio.h>

// Function to check the watering logic based on soil moisture
void check_watering_logic() {
    int moisture_level = read_soil_moisture(); // Read current soil moisture level

    // If moisture is below the threshold, turn on the pump
    if (moisture_level < system_settings.min_moisture_threshold) {
        if (pump_state == PUMP_OFF) {
            turn_pump_on();
            led_state = LED_WATERING;
        }
    } 
    // If moisture is above the threshold, turn off the pump
    else if (moisture_level > system_settings.max_moisture_threshold) {
        if (pump_state == PUMP_ON) {
            turn_pump_off();
        }
    }
}
