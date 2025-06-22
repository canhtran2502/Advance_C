#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#define PRESS_BUTTON (1)
#define RELEASE_BUTTON (0)

// Define system modes
typedef enum {
    MODE_AUTO,
    MODE_MANUAL
} SystemMode;

// Define pump states
typedef enum {
    PUMP_OFF,
    PUMP_ON
} PumpState;

// Define LED states
typedef enum {
    LED_NORMAL,
    LED_WATERING,
    LED_LOW_MOISTURE_ALERT,
    LED_ERROR
} LEDState;

// Structure for system settings
typedef struct {
    int min_moisture_threshold; // Minimum moisture level to trigger watering
    int max_moisture_threshold; // Maximum moisture level to stop watering
    int max_watering_time;      // Maximum time for watering
    int sensor_check_interval;  // Interval for checking sensor data
} SystemSettings;

// Global variables
extern SystemMode current_mode; // Current operating mode of the system
extern PumpState pump_state;     // Current state of the water pump
extern LEDState led_state;       // Current state of the LED
extern SystemSettings system_settings; // System configuration settings

extern volatile uint8_t mode_button;
extern volatile uint8_t pump_button;

// Function to initialize the system
void init_system();

#endif // CONFIG_H
