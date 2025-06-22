#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

typedef enum {
    LOG_EMERGENCY,
    LOG_ALERT,
    LOG_CRITICAL,
    LOG_ERROR,
    LOG_WARNING,
    LOG_NOTICE,
    LOG_INFO,
    LOG_DEBUG
} LogLevel;

void logger_init(const char *filename, LogLevel level);
void logger_set_level(LogLevel level);
void logger_log(LogLevel level, const char *format, ...);
void logger_close();

#define log_message(level, ...) logger_log(level, __VA_ARGS__)

#endif // LOGGER_H
