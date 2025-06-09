#include <stdio.h>
#include <stdlib.h>
#include "lighting.h"

static void turn_light_on(void)
{
    printf("Turn on the light\n");
}

static void turn_light_off(void)
{
    printf("Turn off the light\n");
}

static void set_brighness_ligth(int level)
{
    printf("Set brightness for the light with level: %d %%\n", level);
}

// Function create light system instance.
s_lighting_t* create_light_system(void)
{
    s_lighting_t* system = (s_lighting_t*)malloc(sizeof(s_lighting_t));
    if (system != NULL)
    {   
        system->turn_light_on = turn_light_on;
        system->turn_light_off = turn_light_off;
        system->set_brighness_ligth = set_brighness_ligth;
    }
    else 
    {
        printf("Allocate memory failed\n");
    }

    return system;
}