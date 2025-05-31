#ifndef USER_MNGT_H
#define USER_MNGT_H

#include "common.h"
#include "book_mngt.h"

typedef enum e_user_menu_option
{
    ADD_USER = 1,
    EDIT_USER_INFO,
    DELETE_USER,
    UPDATE_BOOK_BORROW,
    UPDATE_BOOK_RETURN
} e_user_menu_option_t;

typedef enum e_id_user_status
{
    USER_BLANK_SLOT = 0,
    USER_USED_SLOT  = 1
} e_id_user_status_t;

typedef struct s_user_info
{
    int   id;
    int   total_borrow_book;
    char  name[MAX_CHARACTER];
    e_id_user_status_t status;
    s_book_info_t  list_borrowed[MAX_BOOK+1]; //Synchronize ID with array number, do not use array[0]
} s_user_info_t;

void add_user(void);
void edit_user_info(void);
void delete_user(void);
void user_management(void);
int input_user_id(e_user_menu_option_t mode);
void print_infor_user(int id);

#endif