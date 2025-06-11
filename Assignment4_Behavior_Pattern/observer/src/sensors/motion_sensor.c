#include "../../inc/sensors/motion_sensor.h"
#include <stdio.h>

// Initialize the s_door_sensor_t struct
void motion_sensor_init(s_motion_sensor_t *sensor){
    publisher_init(&sensor->base);
    sensor->detect_motion = RESET_VALUE;
}

// Simulate a door event and notify subscribers
void motion_sensor_trigger(s_motion_sensor_t* sensor, int detect_motion) {
    sensor->detect_motion = detect_motion;
    if (detect_motion) {
        sensor->base.notify_subscribers(&sensor->base, "Motion detected");
    } else {
        sensor->base.notify_subscribers(&sensor->base, "No motion");
    }
}
