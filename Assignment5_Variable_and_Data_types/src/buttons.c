#include "buttons.h"
#include "actuators.h"
#include "config.h"
#include <stdio.h>

volatile uint8_t mode_button;
volatile uint8_t pump_button;

// Function to handle button presses
void handle_buttons() {
    // Simulate button press handling
    if (mode_button == PRESS_BUTTON) {
        if (current_mode == MODE_AUTO) {
            current_mode = MODE_MANUAL; // Switch to manual mode
            turn_pump_off(); // Ensure pump is off in manual mode
            printf("Switched to manual mode\n");
        } else {
            current_mode = MODE_AUTO; // Switch to automatic mode
            printf("Switched to automatic mode\n");
        }

        mode_button = RELEASE_BUTTON;
    }

    if ((pump_button == PRESS_BUTTON) && current_mode == MODE_MANUAL) {
        turn_pump_on(); // Turn on the pump for manual watering
        // Simulate watering for 10 seconds
        sleep(10000);
        turn_pump_off(); // Turn off the pump after watering

        pump_button = RELEASE_BUTTON;
    }
}
