#include "sensor_manager.h"

int main()
{
    s_sensor_manager_t* manager = create_sensor_manager();
    s_sensor_manager_t* manager_simulate_fail_case = create_sensor_manager();

    manager -> add_sensor(1, "Temperature");
    manager -> add_sensor(2, "Air");

    manager -> remove_sensor(2);
    manager -> remove_sensor(3);

    manager -> get_sensor_data();

    manager -> upload_sensor_data();

    destroy_sensor_manager();

    return 0;
}