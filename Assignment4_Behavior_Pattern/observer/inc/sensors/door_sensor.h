#ifndef DOOR_SENSOR_H
#define DOOR_SENSOR_H

#include "../subscriber_publisher.h"

#define DOOR_CLOSE  (0)
#define DOOR_OPEN   (1)

// Door sensor struct
typedef struct {
    s_publisher_t base;
    int is_open;
} s_door_sensor_t;

void door_sensor_init(s_door_sensor_t* sensor);
void door_sensor_trigger(s_door_sensor_t* sensor, int open);

#endif // DOOR_SENSOR_H
