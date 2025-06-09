#include <stdio.h>
#include <stdlib.h>
#include "hvac.h"

static void set_temperature(float temperature)
{
    printf("Set temperature to: %.2f C degree\n",temperature);
}

static void set_air_conditioner_mode(const char* mode)
{
    printf("Set air conditioner mode: %s\n", mode);
}

// Function create hvac system instance.
s_hvac_t* create_hvac_system(void)
{
    s_hvac_t* system = (s_hvac_t*)malloc(sizeof(s_hvac_t));
    if (system != NULL)
    {   
        system->set_temperature = set_temperature;
        system->set_air_conditioner_mode = set_air_conditioner_mode;
    }
    else 
    {
        printf("Allocate memory failed\n");
    }

    return system;
}