#include "logger.h"

int main() {
    logger_init("application.log", LOG_WARNING); //Write log into file and set the log level.

    log_message(LOG_DEBUG, "This is a debug message.");
    log_message(LOG_INFO, "Application started.");
    log_message(LOG_WARNING, "This is a warning message.");
    log_message(LOG_ERROR, "An error occurred: %s", "Unable to open file.");
    log_message(LOG_CRITICAL, "Critical error! System shutting down.");

    logger_close();
    return 0;
}
