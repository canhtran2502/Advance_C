#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SENSOR_NAME_LENGTH  (50)
#define MAX_SENSOR_NODE         (20)
#define DATA_SPOT               (20)
#define RESET_VALUE             (0x00)

enum e_status
{
    FAIL = 0,
    SUCCESS
};

typedef struct {
    int id;
    char sensor_name[MAX_SENSOR_NAME_LENGTH];
    float sensor_value;
} s_sensor_node_t;

typedef struct {
    s_sensor_node_t *sensor_node[MAX_SENSOR_NODE];
    void (*add_sensor)(int id, char* sensor_type);
    void (*remove_sensor)();
    void (*get_sensor_data)();
    void (*upload_sensor_data)();
} s_sensor_manager_t;

s_sensor_manager_t* create_sensor_manager(void);
void destroy_sensor_manager(void);
void add_sensor(int id, char* sensor_name);
void remove_sensor(int id);
void get_sensor_data(void);
void upload_sensor_data(void);

#endif