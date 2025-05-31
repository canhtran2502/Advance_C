#include "common.h"
#include "book_mngt.h"
#include "user_mngt.h"
#include "borrow_mngt.h"
#include "search.h"

typedef enum e_main_app_option
{
    BOOK_MANAGEMENT = 1,
    USER_MANAGEMENT,
    BORROW_MANAGEMENT,
    SEARCH_INFO
} e_main_app_option_t;

void main_app_info(void)
{
    printf("=====================================\n");
    printf("Library management application.\n");
    printf("Please select: \n");
    printf("1. Book management\n");
    printf("2. User management\n");
    printf("3. Borrowing book\n");
    printf("4. Searching information: book, user,... \n");
}

void main_app(void)
{
    int option;
    while(TRUE)
    {
        main_app_info();
        scanf("%d",&option);
        switch(option)
        {
            case BOOK_MANAGEMENT:
                book_management();
                break;
            case USER_MANAGEMENT:
                user_management();
                break;
            case BORROW_MANAGEMENT:
                borrow_management();
                break;
            case SEARCH_INFO:
                search_info();
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    }
}

int main(void)
{
    main_app();
}