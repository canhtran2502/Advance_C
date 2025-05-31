#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define RESET_VALUE         (0x00)
#define MAX_CHARACTER       (100)
#define MAX_BOOK            (100)
#define MAX_USER            (100)

enum e_validate_id
{
    ID_VALID       = 0,
    ID_INVALID     
};

enum e_bool
{
    FALSE       = 0,
    TRUE     
};

void main_app_info(void);
void main_app(void);

#endif