#include "stdio.h"
#include "stdlib.h"
#include "security.h"

static void enable_alarm(void)
{
    printf("Enable security alarm \n");
}

static void disable_alarm(void)
{
    printf("Disable security alarm \n");
}

static void monitor_sensor(void)
{
    printf("Monitor sensor\n");
}

// Function create security system instance.
s_security_t* create_security_system(void)
{
    s_security_t* system = (s_security_t*)malloc(sizeof(s_security_t));
    if (system != NULL)
    {   
        system->enable_alarm = enable_alarm;
        system->disable_alarm = disable_alarm;
        system->monitor_sensor = monitor_sensor;
    }
    else 
    {
        printf("Allocate memory failed\n");
    }

    return system;
}