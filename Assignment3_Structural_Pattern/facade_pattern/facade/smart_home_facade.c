#include "stdio.h"
#include "stdlib.h"
#include "smart_home_facade.h"

s_smart_home_facade_t* create_smart_home_facade(void)
{
    s_smart_home_facade_t* facade = (s_smart_home_facade_t*)malloc(sizeof(s_smart_home_facade_t));

    facade->hvac= create_hvac_system();
    facade->lighting = create_light_system();
    facade->security = create_security_system();

    return facade;
}

void activate_morning_routine(s_smart_home_facade_t* facade)
{
    facade->lighting->turn_light_on();
    facade->lighting->set_brighness_ligth(100);
    facade->security->disable_alarm();
    facade->hvac->set_temperature(25);
    facade->hvac->set_air_conditioner_mode("Cooling");
    printf("Morning routine activated.\n");
}

void activate_away_mode(s_smart_home_facade_t* facade)
{
    facade->lighting->turn_light_off();
    facade->lighting->set_brighness_ligth(20);
    facade->security->enable_alarm();
    facade->security->monitor_sensor();
    facade->hvac->set_temperature(30);
    facade->hvac->set_air_conditioner_mode("Echo");
    printf("Away mode activated.\n");
}
void set_movie_night_scene(s_smart_home_facade_t* facade)
{
    facade->lighting->turn_light_on();
    facade->lighting->set_brighness_ligth(30);
    facade->security->monitor_sensor();
    facade->hvac->set_temperature(20);
    facade->hvac->set_air_conditioner_mode("Cooling");
    printf("Movie night activated.\n");
}