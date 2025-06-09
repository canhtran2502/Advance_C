#ifndef SECURITY_H
#define SECURITY_H

typedef struct {
    void (*enable_alarm)(void);
    void (*disable_alarm)(void);
    void (*monitor_sensor)(void);
} s_security_t;

s_security_t* create_security_system(void);

#endif