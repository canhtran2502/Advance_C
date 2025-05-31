#ifndef BORROW_MNGT_H
#define BORROW_MNGT_H

#include "common.h"
#include "book_mngt.h"
#include "user_mngt.h"
#include "search.h"

typedef enum e_borrow_book_menu_t
{
    BORROW = 1,
    RETURN,
    DISPLAY_BOOK_NUMBER,
} e_borrow_book_menu_t;

void borrow_management(void);

#endif