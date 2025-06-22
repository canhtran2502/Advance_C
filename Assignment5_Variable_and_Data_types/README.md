# Smart Plant Watering System (SPWS)

## Table of Contents
1. [Introduction](#introduction)
2. [Assumed Hardware and Resources](#assumed-hardware-and-resources)
3. [Software Requirements](#software-requirements)
4. [Functional Requirements](#functional-requirements)
5. [Implementation Requirements](#implementation-requirements)
6. [How to run application](#how-to-run-application)
7. [Summary of Knowledge](#summary-of-knowledge)

## Introduction
This project involves designing and programming an embedded system to manage the watering of plants. The system should be capable of reading sensor data, making watering decisions based on configuration parameters, and notifying the operational status. The goal is to realize a practical automation system with requirements for state management, data handling, and user interaction.

## Assumed Hardware and Resources
- **Microcontroller**: A popular microcontroller with basic resources (GPIO, Timer, ADC, sufficient RAM/Flash for a small application).
- **Sensors**:
  - **Soil Moisture Sensor**: Measures the percentage of soil moisture (0-100%).
  - **Ambient Temperature Sensor**: Measures the surrounding air temperature.
- **Devices**:
  - **Mini Water Pump**: Controlled to TURN ON/OFF watering.
  - **Status LED**: An RGB LED or three single-color LEDs to indicate operational status (Green - normal, Yellow - watering, Red - error/warning).
  - **Buttons**: Two physical buttons:
    - Button 1: TOGGLE automatic mode.
    - Button 2: Trigger manual watering (when the system is in standby).

## Software Requirements
### Define Operational States
- **System Modes**:
  - `MODE_AUTO`: The system automatically manages watering based on sensors.
  - `MODE_MANUAL`: The system waits for manual commands or is locked out of automatic mode.
- **Pump Watering States**:
  - `PUMP_OFF`: The pump is not operating.
  - `PUMP_ON`: The pump is operating.
- **LED States**:
  - `LED_NORMAL`: The system is operating normally, not watering.
  - `LED_WATERING`: The system is currently watering.
  - `LED_LOW_MOISTURE_ALERT`: Soil moisture is too low (not watered or insufficient watering).
  - `LED_ERROR`: System error (e.g., sensor failure, pump jam).

### Main Data Structures
- **Sensor Data**: A structure to store values read from the soil moisture and temperature sensors.
- **System Settings**: A structure to store configuration parameters such as:
  - Minimum moisture threshold to start watering.
  - Maximum moisture threshold to stop watering.
  - Maximum watering time per session.
  - Sensor check interval (e.g., every 5 minutes).
  - Current mode status (Automatic/Manual).

## Functional Requirements
### System Initialization
- Set up GPIO pins for the sensors, pump, LEDs, and buttons.
- Initialize default values for system settings (moisture thresholds, watering time, etc.).
- Start the system in `MODE_AUTO` by default.

### Read and Process Sensor Data
- Periodically read values from the soil moisture and temperature sensors.
- Store these values in the sensor data structure.
- Optionally perform data smoothing (averaging) if necessary.

### Automatic Watering Control Logic
- If the system is in `MODE_AUTO`:
  - Compare the current soil moisture with the minimum watering threshold.
  - If moisture is too low and the waiting time between waterings has elapsed, activate the pump.
  - While the pump is active, continue monitoring moisture and stop the pump when the maximum threshold is reached or the maximum watering time has elapsed.
  - A timer should manage the sensor check cycle and watering time.

### Pump Control
- Turn ON/OFF the water pump based on control logic decisions.
- Implement functions to control pump state (`turn_pump_on()`, `turn_pump_off()`).

### Status LED Control
- Continuously update the LED color based on the system's operational state (normal, watering, low moisture, error).

### Button Handling
- **Toggle Automatic Mode Button**: When pressed, switch between `MODE_AUTO` and `MODE_MANUAL`. Ensure the pump is OFF when switching to `MODE_MANUAL`.
- **Manual Watering Button**: Only effective when the system is in `MODE_MANUAL`. When pressed, activate the water pump for a fixed duration (e.g., 10 seconds), then automatically turn off.

### Status Notifications
- Periodically or when significant state changes occur, send notifications about the system status (e.g., "Soil moisture: 35%", "Watering...", "Mode: Manual").
- Optimize memory usage: Avoid using too many fixed character strings (`const char*`) if Flash space is limited. Use enumerations or codes to represent notifications.

### Main Loop Operation
- After initialization, the system will run in an infinite loop.
- In each loop iteration, the system will:
  - Check and handle button events.
  - If in automatic mode, check and process watering logic.
  - Update LED status.
  - Optionally send periodic status reports.
  - Include a small delay to save energy and align with the operational cycle.

## Implementation Requirements
- Implement all functionalities of the SPWS in the C programming language.
- Organize the source code clearly and readably, with separate header and source files for each module (e.g., main.c, sensors.c, watering_logic.c, actuators.c, buttons.c, config.h).
- Use appropriate enums and structs to manage states and data.
- Manage static and extern variables appropriately to control scope and share data between modules.
- Simulate the operation of sensors, water pump, LEDs, and buttons by printing messages to the console and changing states accordingly.
- Ensure the system can smoothly switch between modes and handle situations such as low moisture, high moisture, or user intervention.

## How to run application
- Use the command `make` to build the project. -> $./SPWS to run application.
- Use the command `make clean` to clean up the project.

## Summary of Knowledge
### Variables and Structures in C
- **Variables**: Define variables for sensor readings, system states, and configuration parameters.
- **Structures**: Use structures to group related data, such as sensor data and system settings.

This documentation aims to provide a comprehensive understanding of the design and implementation of the Smart Plant Watering System. If you have any questions, please feel free to reach out.
