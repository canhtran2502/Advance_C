#include "borrow_mngt.h"

extern s_book_info_t book_info[MAX_BOOK + 1]; //Synchronize ID with array number, do not use array[0]
extern s_user_info_t user_info[MAX_USER + 1]; //Synchronize ID with array number, do not use array[0]
static void borrow_book_print(void);
static void borrow_book(void);
static void return_book(void);
static void display_book_number(void);

static void borrow_book_print(void)
{
    printf("=====================================\n");
    printf("Please select: \n");
    printf("1. Borrow book\n");
    printf("2. Return book\n");
    printf("3. Summary number book\n");
    printf("4. Back to main menu\n");
}

static void borrow_book(void)
{
    printf("=====================================\n");
    printf("Borrow Book. \n");
    printf("Please input your information \n");
    int temp_user_id = input_user_id(UPDATE_BOOK_BORROW);

    (void)display_available_book();

    printf("Please input book ID: \n");
    int temp_book_id = input_book_id(BORROW_BOOK);

    if (book_info[temp_book_id].status == AVAILABLE)
    {
        printf ("You can borrowed book has ID: %d\n",temp_book_id);
        
        book_info[temp_book_id].status = BORROWED;

        for (int i=1; i<= (user_info[temp_user_id].total_borrow_book + 1); i++)
        {
            if (user_info[temp_user_id].list_borrowed[i].id == 0)
            {
                memcpy(&user_info[temp_user_id].list_borrowed[i],&book_info[temp_book_id],sizeof(book_info[temp_book_id]));
            }
        }
        
        user_info[temp_user_id].total_borrow_book++;
    }
    else if (book_info[temp_book_id].status == BORROWED)
    {
        printf ("This book is not available. Please borrow another book.\n");
    }
}

static void return_book(void)
{
    printf("Return Book. \n");
    printf("Please input your information \n");
    int temp_user_id = input_user_id(UPDATE_BOOK_BORROW);

    printf("Please input book ID: \n");
    int temp_book_id = input_book_id(BORROW_BOOK);

    if (book_info[temp_book_id].status == BORROWED)
    {
        for (int i=1; i <= (user_info[temp_user_id].total_borrow_book + 1); i++)
        {
            if (user_info[temp_user_id].list_borrowed[i].id == temp_book_id)
            {
                memset(&user_info[temp_user_id].list_borrowed[i], RESET_VALUE, sizeof(user_info[temp_user_id].list_borrowed[i]));
                book_info[i].status = AVAILABLE;
                user_info[temp_user_id].total_borrow_book--;
                break;
            }
        }
    }
    else
    {
        printf ("This book does not exist or be still in library. Please input correct ID book.\n");
    }
}

static void display_book_number(void)
{
    printf("Display book status in library \n");

    int total_borrowed_book = RESET_VALUE;
    int total_available_book = RESET_VALUE;

    for (int i=1; i <= MAX_BOOK; i++)
    {
        if (book_info[i].status == AVAILABLE)
        {
            total_available_book++;
        }
        else if (book_info[i].status == BORROWED)
        {
            total_borrowed_book++;
        }
    }

    printf ("Available book: %d \n", total_available_book);
    printf ("Borrowed book: %d \n", total_borrowed_book);
}

void borrow_management(void)
{
    int option;
    while(TRUE)
    {
        borrow_book_print();
        scanf("%d",&option);
        switch(option)
        {
            case BORROW:
                borrow_book();
                break;

            case RETURN:
                return_book();
                break;

            case DISPLAY_BOOK_NUMBER:
                display_book_number();
                break;

            case BACK_TO_MAIN:
                main_app();
                break;            

            default:
                break;
        }
    }
}