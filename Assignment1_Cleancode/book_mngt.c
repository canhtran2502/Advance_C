#include "book_mngt.h"
#include "search.h"

s_book_info_t book_info[MAX_BOOK + 1]; //Synchronize ID with array number, do not use array[0]
int available_book = RESET_VALUE;

static bool validate_book_id(int* id, e_book_menu_option_t mode);
static void book_menu_print(void);
void print_infor_book(int id);

static void book_menu_print(void)
{
    printf("=====================================\n");
    printf("Please select: \n");
    printf("1. Add new book\n");
    printf("2. Edit book information\n");
    printf("3. Delete book\n");
    printf("4. Back to main menu\n");
}

void print_infor_book(int id)
{   
    printf("Book ID: %d\n", id);
    printf("Author: %s\n", book_info[id].author);
    printf("Title: %s\n", book_info[id].title);

    char* status;
    switch (book_info[id].status)
    {
        case BLANK_SLOT:
            status = "Blank slot";
            break;
        case AVAILABLE:
            status = "Available";
            break;
        case BORROWED:
            status = "Borrowed";
            break;
        default:
            break;
    }
    printf("Status: %s\n", status);
    printf("=====================================\n");
}

static bool validate_book_id(int* id, e_book_menu_option_t mode)
{
    if ((*id <= 0) || (*id > MAX_BOOK))
    {
        printf("ID out range 1 - %d\n",MAX_BOOK);
        return ID_INVALID;
    }

    switch (mode)
    {
        case ADD_BOOK:
            if (book_info[*id].status != BLANK_SLOT)
            {   
                printf("This ID belongs to another book. Please input another value\n");
                return ID_INVALID;
            }
            break;

        case EDIT_BOOK_INFO:
        case DELETE_BOOK:
        case BORROW_BOOK:
        case RETURN_BOOK:
            if (book_info[*id].status == BLANK_SLOT)
            {
                printf("There is no book with this ID. Please input another value\n");
                return ID_INVALID;
            }

        default:
            break;
    }
    return ID_VALID ;
}

int input_book_id(e_book_menu_option_t mode)
{
    int temp_id = RESET_VALUE;
    do 
    {
        printf("ID: ");
        scanf("%d",&temp_id);
        getchar();
    }
    while(validate_book_id(&temp_id,mode));

    return temp_id;
}

void add_book(void)
{
    if(available_book < MAX_BOOK)
    {
        printf("Please input book infomation: \n");

        int temp_id = input_book_id(ADD_BOOK);
        book_info[temp_id].id = temp_id;

        printf("Author: ");
        fgets(book_info[temp_id].author, MAX_CHARACTER, stdin);
        book_info[temp_id].author[strcspn(book_info[temp_id].author, "\n")] = '\0';

        printf("Title: ");
        fgets(book_info[temp_id].title, MAX_CHARACTER, stdin);
        book_info[temp_id].title[strcspn(book_info[temp_id].title, "\n")] = '\0';

        book_info[temp_id].status = AVAILABLE;

        printf("Added new book into library:\n");
        print_infor_book(temp_id);
        available_book++;
    }
    else 
    {
        printf("Library is full. Cannot add new book.\n");
    }
}

void edit_book_info(void)
{
    if (display_available_book())
    {
        printf("Please input the id book need to be edited: \n");
        int temp_id = input_book_id(EDIT_BOOK_INFO);

        printf("Current book information: \n");
        print_infor_book(temp_id);
        
        printf("Editing infor:\n");

        printf("Author: ");
        fgets(book_info[temp_id].author, MAX_CHARACTER, stdin);
        book_info[temp_id].author[strcspn(book_info[temp_id].author, "\n")] = '\0';

        printf("Title: ");
        fgets(book_info[temp_id].title, MAX_CHARACTER, stdin);
        book_info[temp_id].title[strcspn(book_info[temp_id].title, "\n")] = '\0';

        printf("Status: Choose (1)-Available or (2)-Borrowed\n");
        printf("1. Available\n");
        printf("2. Borrowed\n");
        while (TRUE)
        {
            int temp_input;
            scanf("%d", &temp_input);
            if (temp_input == AVAILABLE)
            {
                book_info[temp_id].status = AVAILABLE;
                break;
            }
            else if (temp_input == BORROWED)
            {
                book_info[temp_id].status = BORROWED;
                break;
            }
            printf("Please choose (1) or (2)\n");
        }

        printf("\nEdited. New information:\n");
        print_infor_book(temp_id);
    }
    else
    {
        /*There are no available book to edit*/
    }
    
}

void delete_book(void)
{
    if (display_available_book())
    {
        printf("Please input the id book need to be deleted: \n");
        int temp_id = input_book_id(DELETE_BOOK);

        printf("Deleting book below: \n");
        print_infor_book(temp_id);
        memset(&book_info[temp_id], RESET_VALUE, sizeof(book_info[temp_id]));

        printf("Deleted\n");
        available_book--;
    }
    else
    {
        /*There are no available book to edit*/
    }
}

void book_management(void)
{
    int option;
    while(TRUE)
    {
        book_menu_print();
        scanf("%d",&option);
        switch(option)
        {
            case ADD_BOOK:
                add_book();
                break;

            case EDIT_BOOK_INFO:
                edit_book_info();
                break;

            case DELETE_BOOK:
                delete_book();
                break;

            case BACK_TO_MAIN:
                main_app();
                break;            

            default:
                break;
        }
    }
}