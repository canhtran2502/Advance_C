#ifndef HVAC_H
#define HVAC_H

typedef struct {
    void (*set_temperature)(float temperature);
    void (*set_air_conditioner_mode)(const char* mode);
} s_hvac_t;

s_hvac_t* create_hvac_system(void);

#endif