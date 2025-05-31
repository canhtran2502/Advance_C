#include "common.h"
#include "search.h"

extern s_book_info_t book_info[MAX_BOOK + 1]; //Synchronize ID with array number, do not use array[0]
extern s_user_info_t user_info[MAX_USER + 1]; //Synchronize ID with array number, do not use array[0]
static void search_info_print(void);
static void search(void);
static void search_title(void);
static void search_author(void);
static void search_menu_print(void);

void search_info_print(void)
{
    printf("=====================================\n");
    printf("Please select: \n");
    printf("1. Search information\n");
    printf("2. Display available book in library\n");
    printf("3. Display user information\n");
    printf("4. Back to main menu\n");
}

void search_menu_print()
{
    printf("Search information\n");
    printf("=====================================\n");
    printf("Please select: \n");
    printf("1. Search book title\n");
    printf("2. Search book author\n");
    printf("3. Back to search menu\n");
}

int display_available_book()
{
    printf("Display available book\n");
    int count = RESET_VALUE;
    for(int i=1; i <= MAX_BOOK; i++)
    {
        if (book_info[i].status == AVAILABLE)
        {
            print_infor_book(i);
            count++;
        }
    }

    if (count == RESET_VALUE)
    {
        printf("There is no available book\n");
    }
    return count;
}

int display_user_infor(void)
{
    printf("Display user information\n");
    int count = RESET_VALUE;
    for(int i=1; i <= MAX_USER; i++)
    {
        if (user_info[i].status == USER_USED_SLOT)
        {
            print_infor_user(i);
            count++;
        }
    }

    if (count == RESET_VALUE)
    {
        printf("There is no user\n");
    }
    return count;
}

void search_info(void)
{
    int option;
    while(TRUE)
    {
        search_info_print();
        scanf("%d",&option);
        switch(option)
        {
            case SEARCH:
                search();
                break;

            case DISPLAY_AVAILABLE_BOOK:
                (void)display_available_book();
                break;

            case DISPLAY_USER_INFOR:
                (void)display_user_infor();
                break;

            case BACK_TO_MAIN:
                main_app();
                break;            

            default:
                break;
        }
    }
}
static void search_title(void)
{
    printf("Search title\n");
    printf("Please input book title: ");
    
    char title[MAX_CHARACTER];
    getchar();
    fgets(title, MAX_CHARACTER, stdin);
    title[strcspn(title, "\n")] = '\0';

    // printf("title: %s",title);

    int count = RESET_VALUE;
    for (int i=1; i <= MAX_BOOK; i++)
    {
        if (!strcmp(title, book_info[i].title))
        {
            print_infor_book(i);
            count++;
        }
    }

    if (count == RESET_VALUE)
    {
        printf("There is no book has this title\n");
    }
}

void search_author(void)
{
    printf("Search author\n");
    printf("Please input book author: ");
    getchar();
    char author[MAX_CHARACTER];
    fgets(author, MAX_CHARACTER, stdin);
    author[strcspn(author, "\n")] = '\0';

    int count = RESET_VALUE;
    for (int i=1; i <= MAX_BOOK; i++)
    {
        if (!strcmp(author, book_info[i].author))
        {
            print_infor_book(i);
            count++;
        }
    }

    if (count == RESET_VALUE)
    {
        printf("There is no book has this author\n");
    }
}
void search(void)
{
    int option;
    while(TRUE)
    {
        search_menu_print();
        scanf("%d",&option);
        switch(option)
        {
            case SEARCH_TITLE:
                search_title();
                break;

            case SEARCH_AUTHOR:
                search_author();
                break;

            case BACK_TO_SEARCH_MENU:
                search_info();
                break;            

            default:
                break;
        }
    }

}