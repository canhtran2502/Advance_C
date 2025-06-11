#include "../../inc/sensors/temperature_sensor.h"
#include <stdlib.h>
#include <stdio.h>

// Initialize the s_smoke_sensor_t struct
void temperature_sensor_init (s_temperature_sensor_t* sensor){
    publisher_init(&sensor->base);
    sensor->temperature = RESET_VALUE;
}

// Simulate a smoke event and notify subscribers
void temperature_sensor_trigger(s_temperature_sensor_t* sensor, int temperature) {
    sensor->temperature = temperature;
    char* temperature_message[MAX_CHARACTER];
    sprintf(temperature_message,"Temperature: %d C degree",sensor->temperature);
    sensor->base.notify_subscribers(&sensor->base, (const char*)temperature_message);
}
