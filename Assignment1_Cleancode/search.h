#ifndef SEARCH_H
#define SEARCH_H

#include "common.h"
#include "book_mngt.h"
#include "user_mngt.h"

typedef enum e_search_info_menu_t
{
    SEARCH = 1,
    DISPLAY_AVAILABLE_BOOK,
    DISPLAY_USER_INFOR
} e_search_info_menu_t;

typedef enum e_search_book_t
{
    SEARCH_TITLE = 1,
    SEARCH_AUTHOR,
    BACK_TO_SEARCH_MENU
} e_search_book_t;

void search_info(void);
int display_available_book(void);
int display_user_infor(void);

#endif