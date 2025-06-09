#ifndef SMART_HOME_FACADE_H
#define SMART_HOME_FACADE_H

#include "../lighting/lighting.h"
#include "../security/security.h"
#include "../HVAC/hvac.h"

typedef struct {
    s_hvac_t*     hvac;
    s_security_t* security;
    s_lighting_t* lighting;
} s_smart_home_facade_t;

void activate_morning_routine(s_smart_home_facade_t* facade);
void activate_away_mode(s_smart_home_facade_t* facade);
void set_movie_night_scene(s_smart_home_facade_t* facade);

s_smart_home_facade_t* create_smart_home_facade(void);

#endif