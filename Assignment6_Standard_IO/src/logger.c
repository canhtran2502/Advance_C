#include "logger.h"
#include <stdlib.h>
#include <string.h>

static FILE *log_file = NULL;
static LogLevel current_level = LOG_DEBUG;

void logger_init(const char *filename, LogLevel level) {
    if (filename) {
        log_file = fopen(filename, "a");
        if (!log_file) {
            perror("Failed to open log file");
            exit(EXIT_FAILURE);
        }
    }
    current_level = level;
}

void logger_set_level(LogLevel level) {
    current_level = level;
}

void logger_log(LogLevel level, const char *format, ...) {
    if (level > current_level) return;

    // Get the current time
    time_t now;
    time(&now);
    struct tm *t = localtime(&now);
    
    char timestamp[40];
    snprintf(timestamp, sizeof(timestamp), "[%04d-%02d-%02d %02d:%02d:%02d]",
             t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
             t->tm_hour, t->tm_min, t->tm_sec);

    // Prepare the log message
    va_list args;
    va_start(args, format);
    
    char message[256];
    vsnprintf(message, sizeof(message), format, args);
    va_end(args);

    // Format the final log message
    const char *level_str[] = {"EMERGENCY", "ALERT", "CRITICAL", "ERROR", "WARNING", "NOTICE", "INFO", "DEBUG"};
    char log_entry[512];
    snprintf(log_entry, sizeof(log_entry), "%s [%s] [%s:%d] - %s\n", 
             timestamp, level_str[level], __FILE__, __LINE__, message);

    // Output to console and file
    if (level <= LOG_ERROR) {
        fprintf(stderr, "%s", log_entry); // For serious errors
    } else {
        fprintf(stdout, "%s", log_entry); // For normal logs
    }

    if (log_file) {
        fprintf(log_file, "%s", log_entry); // Log to file if opened
        fflush(log_file); // Ensure it's written immediately
    }
}

void logger_close() {
    if (log_file) {
        fclose(log_file);
        log_file = NULL;
    }
}
