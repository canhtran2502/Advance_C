#include "sensors.h"
#include "config.h"
#include <stdio.h>

// Function to read soil moisture level
int read_soil_moisture() {
    // Simulate reading sensor data for soil moisture
    return rand() % 100; // Random value between 0-100
}

// Function to read temperature
int read_temperature() {
    // Simulate reading sensor data for temperature
    return 25; // Fixed value for demonstration
}
