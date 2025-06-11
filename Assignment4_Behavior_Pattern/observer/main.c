#include "inc/sensors/door_sensor.h"
#include "inc/sensors/motion_sensor.h"
#include "inc/sensors/temperature_sensor.h"
#include "inc/sensors/smoke_sensor.h"
#include "subscribers/mobile_app_notifier.h"
#include "subscribers/alarm_system_controller.h"
#include "subscribers/hvac_system.h"
#include "subscribers/event_recording.h"
#include <stdio.h>

int main() {
    // Initialize sensors (publishers)
    s_door_sensor_t door_sensor;
    door_sensor_init(&door_sensor);

    s_smoke_sensor_t smoke_sensor;
    smoke_sensor_init(&smoke_sensor);

    s_motion_sensor_t motion_sensor;
    motion_sensor_init(&motion_sensor);

    s_temperature_sensor_t temperature_sensor;
    temperature_sensor_init(&temperature_sensor);

    // Initialize subscribers
    s_mobile_app_notifier_t mobile_app;
    mobile_app_notifier_init(&mobile_app);

    s_alarm_system_controller_t alarm_system;
    alarm_system_controller_init(&alarm_system);

    s_hvac_system_t hvac_system;
    hvac_system_init(&hvac_system);

    s_event_recording_t event_recording;
    event_recording_init(&event_recording);

    // Register subscribers to door sensor (publisher)
    door_sensor.base.subscribe(&door_sensor.base, (s_subscriber_t*)&mobile_app);
    door_sensor.base.subscribe(&door_sensor.base, (s_subscriber_t*)&alarm_system);
    door_sensor.base.subscribe(&door_sensor.base, (s_subscriber_t*)&hvac_system);
    door_sensor.base.subscribe(&door_sensor.base, (s_subscriber_t*)&event_recording);

    // Register subscribers to smoke sensor (publisher)
    smoke_sensor.base.subscribe(&smoke_sensor.base, (s_subscriber_t*)&mobile_app);
    smoke_sensor.base.subscribe(&smoke_sensor.base, (s_subscriber_t*)&alarm_system);
    smoke_sensor.base.subscribe(&smoke_sensor.base, (s_subscriber_t*)&hvac_system);
    smoke_sensor.base.subscribe(&smoke_sensor.base, (s_subscriber_t*)&event_recording);

    // Register subscribers to motion sensor (publisher)
    motion_sensor.base.subscribe(&motion_sensor.base, (s_subscriber_t*)&mobile_app);
    motion_sensor.base.subscribe(&motion_sensor.base, (s_subscriber_t*)&alarm_system);
    motion_sensor.base.subscribe(&motion_sensor.base, (s_subscriber_t*)&hvac_system);
    motion_sensor.base.subscribe(&motion_sensor.base, (s_subscriber_t*)&event_recording);

    // Register subscribers to temperature sensor (publisher)
    temperature_sensor.base.subscribe(&temperature_sensor.base, (s_subscriber_t*)&mobile_app);
    temperature_sensor.base.subscribe(&temperature_sensor.base, (s_subscriber_t*)&alarm_system);
    temperature_sensor.base.subscribe(&temperature_sensor.base, (s_subscriber_t*)&hvac_system);
    temperature_sensor.base.subscribe(&temperature_sensor.base, (s_subscriber_t*)&event_recording);

    // Simulate events
    printf("== Simulate Door Open Event ==\n");
    door_sensor_trigger(&door_sensor, DOOR_CLOSE);

    printf("\n== Simulate Smoke Detected Event ==\n");
    smoke_sensor_trigger(&smoke_sensor, DETECTED_SMOKE);

    printf("\n== Simulate Motion Detected Event ==\n");
    motion_sensor_trigger(&motion_sensor, DETECTED_MOTION);

    printf("\n== Simulate Temperature Notification Event ==\n");
    temperature_sensor_trigger(&temperature_sensor, TEMPERATURE_SIMULATE);

    return 0;
}
