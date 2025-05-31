#include "sensor_manager.h"

static s_sensor_manager_t* sensor_manager_instance = NULL;

s_sensor_manager_t* create_sensor_manager(void)
{
    printf("Create sensor manager\n");
    if (NULL != sensor_manager_instance)
    {
        printf("Error: A sensor manager already exists! Cannot create another one.\n");
        return NULL;
    }
    else 
    {
        sensor_manager_instance = (s_sensor_manager_t*)malloc(sizeof(s_sensor_manager_t));
        if (NULL != sensor_manager_instance)
        {   
            memset (sensor_manager_instance->sensor_node, RESET_VALUE, sizeof(sensor_manager_instance->sensor_node));
            sensor_manager_instance->add_sensor = add_sensor;
            sensor_manager_instance->remove_sensor = remove_sensor;
            sensor_manager_instance->get_sensor_data = get_sensor_data;
            sensor_manager_instance->upload_sensor_data = upload_sensor_data;

            printf("Create a sensor manager instance successfully\n");
        }
        else
        {
            printf("Error: allocate memory for instance failed\n");
            return NULL;
        }
    }

    return sensor_manager_instance;
}

void add_sensor(int id, char* sensor_name)
{
    printf("Add new sensor\n");

    bool b_add_success = FAIL;

    for (int i=0; i< MAX_SENSOR_NODE; i++)
    {
        if (NULL == sensor_manager_instance->sensor_node[i])
        {
            sensor_manager_instance->sensor_node[i] = (s_sensor_node_t* )malloc(sizeof(s_sensor_node_t));
            if (NULL != sensor_manager_instance->sensor_node[i])
            {
                sensor_manager_instance->sensor_node[i]->id = id;
                snprintf(sensor_manager_instance->sensor_node[i]->sensor_name, MAX_SENSOR_NAME_LENGTH, "%s", sensor_name);
                sensor_manager_instance->sensor_node[i]->sensor_value = RESET_VALUE;

                printf ("Added sensor: ID = %d, Sensor name: %s\n", 
                sensor_manager_instance->sensor_node[i]->id,
                sensor_manager_instance->sensor_node[i]->sensor_name);
            }
            else
            {
                printf("Error: allocate memory for sensor node failed\n");
            }
            b_add_success = SUCCESS;
            break;
        }
    }

    if (FAIL == b_add_success)
    {
        printf("Cannot add sensor because system has full sensor slot.\n");
    }
}

void remove_sensor(int id)
{
    printf("Remove sensor ID = %d\n", id);

    bool b_remove_success = FAIL;

    for (int i=0; i< MAX_SENSOR_NODE; i++)
    {
        if (NULL != sensor_manager_instance->sensor_node[i])
        {
            if (id == sensor_manager_instance->sensor_node[i]->id)
            {
                free(sensor_manager_instance->sensor_node[i]);
                sensor_manager_instance->sensor_node[i] = NULL;

                printf("Remove sensor ID = %d successfully\n", id);

                b_remove_success = SUCCESS;
            }
        }
    }
    
    if (FAIL == b_remove_success)
    {
        printf("Cannot remove sensor becaue not found any sensor with ID = %d\n", id);
    }
}

void get_sensor_data(void)
{
    printf("Get sensor data\n");

    for (int i=0; i< MAX_SENSOR_NODE; i++)
    {
        if (NULL != sensor_manager_instance->sensor_node[i])
        {
            sensor_manager_instance->sensor_node[i]->sensor_value = (float)(rand() % 100);
            printf("Get Sensor ID: %d, Name: %s, Value: %.2f\n", 
            sensor_manager_instance->sensor_node[i]->id, 
            sensor_manager_instance->sensor_node[i]->sensor_name, 
            sensor_manager_instance->sensor_node[i]->sensor_value);

        }
    }
}
void upload_sensor_data(void)
{
    printf("Upload sensor data\n");

    for (int i=0; i< MAX_SENSOR_NODE; i++)
    {
        if (NULL != sensor_manager_instance->sensor_node[i])
        {
            printf("===============================\n");
            printf("Upload sensor data to data base\n");
            printf("Sensor ID = %d\n",sensor_manager_instance->sensor_node[i]->id);
            printf("Sensor name = %s\n",sensor_manager_instance->sensor_node[i]->sensor_name);
            printf("Sensor value = %.2f\n", sensor_manager_instance->sensor_node[i]->sensor_value);
        }
    }
}

void destroy_sensor_manager(void)
{
    printf("Destroy sensor manager interface and free memory\n");

    for (int i = 0; i < MAX_SENSOR_NODE; i++)
    {
        if (NULL != sensor_manager_instance->sensor_node[i])
        {
            free(sensor_manager_instance->sensor_node[i]);
            sensor_manager_instance->sensor_node[i] = NULL;
        }
    }

    free(sensor_manager_instance);
}