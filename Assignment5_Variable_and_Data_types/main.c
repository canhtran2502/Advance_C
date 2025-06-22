#include "config.h"
#include "sensors.h"
#include "watering_logic.h"
#include "actuators.h"
#include "buttons.h"

SystemSettings system_settings;
SystemMode current_mode;

void send_status_report();
void send_status_report()
{
    printf("Send report simulation\n");
}
void init_system() 
{
    // Default value
    system_settings.min_moisture_threshold = 30; 
    system_settings.max_moisture_threshold = 70; 
    system_settings.max_watering_time = 60;      
    system_settings.sensor_check_interval = 5;

    current_mode = MODE_AUTO;
}

// Main function to initialize and run the system
int main() {
    // Initialize the system components
    init_system();

    while (1) {
        // Handle button presses
        handle_buttons();

        // If in automatic mode, check watering logic
        if (current_mode == MODE_AUTO) {
            check_watering_logic();
        }

        // Update LED status based on system state
        update_led_status();

        // Send periodic status report
        send_status_report();

        // Wait for a short duration
        sleep(1); // 1 second
    }

    return 0;
}
