#ifndef SENSOR_H
#define SENSOR_H

typedef struct {
    void (*init)(void);
    float (*read)(void);
} s_sensor_t;

#endif