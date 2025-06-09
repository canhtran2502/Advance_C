#include "stdio.h"
#include "stdlib.h"
#include "facade/smart_home_facade.h"

static void deinitialize(s_smart_home_facade_t * smart_home)
{
    free(smart_home->hvac);
    free(smart_home->lighting);
    free(smart_home->security);

    free(smart_home);
}   

int main()
{
    s_smart_home_facade_t* smart_home = create_smart_home_facade();

    printf(">>> Activating morning routine...\n");
    activate_morning_routine(smart_home);
    
    printf("\n>>> Activating away mode...\n");
    activate_away_mode(smart_home);
    
    printf("\n>>> Setting movie night scene...\n");
    set_movie_night_scene(smart_home);

    deinitialize(smart_home);
}


