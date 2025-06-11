#include "../../inc/sensors/door_sensor.h"
#include <stdio.h>

// Initialize the s_door_sensor_t struct
void door_sensor_init(s_door_sensor_t* sensor) {
    publisher_init(&sensor->base);
    sensor->is_open = RESET_VALUE;
}

// Simulate a door event and notify subscribers
void door_sensor_trigger(s_door_sensor_t* sensor, int open) {
    sensor->is_open = open;
    if (open) {
        sensor->base.notify_subscribers(&sensor->base, "Door Opened");
    } else {
        sensor->base.notify_subscribers(&sensor->base, "Door Closed");
    }
}
