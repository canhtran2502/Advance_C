#ifndef BOOK_MNGT_H
#define BOOK_MNGT_H

#include "common.h"

typedef enum e_book_menu_option
{
    NONE,
    ADD_BOOK = 1,
    EDIT_BOOK_INFO,
    DELETE_BOOK,
    BACK_TO_MAIN,
    BORROW_BOOK,
    RETURN_BOOK,
} e_book_menu_option_t;

typedef enum e_book_status
{
    BLANK_SLOT  = 0,
    AVAILABLE   = 1, 
    BORROWED    = 2
} e_book_status_t;

typedef struct s_book_info
{
    int   id;
    char title[MAX_CHARACTER];
    char author[MAX_CHARACTER];
    e_book_status_t status;
} s_book_info_t;

void add_book(void);
void edit_book_info(void);
void delete_book(void);
void book_management(void);
void print_infor_book(int id);
int input_book_id(e_book_menu_option_t mode);

#endif