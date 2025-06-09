#ifndef LIGHTING_H
#define LIGHTING_H

typedef struct {
    void (*turn_light_on)(void);
    void (*turn_light_off)(void);
    void (*set_brighness_ligth)(int level);
} s_lighting_t;

s_lighting_t* create_light_system(void);

#endif