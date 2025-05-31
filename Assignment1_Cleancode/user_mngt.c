#include "common.h"
#include "book_mngt.h"
#include "user_mngt.h"
#include "search.h"

s_user_info_t user_info[MAX_USER + 1]; //Synchronize ID with array number, do not use array[0]
int available_user = RESET_VALUE;

static bool validate_user_id(int* id, e_user_menu_option_t mode);
static void user_menu_print(void);

static void user_menu_print(void)
{
    printf("=====================================\n");
    printf("Please select: \n");
    printf("1. Add new user\n");
    printf("2. Edit user information\n");
    printf("3. Delete user\n");
    printf("4. Back to main menu\n");
}

void print_infor_user(int id)
{   
    printf("User ID: %d\n", id);

    printf("Name: %s\n", user_info[id].name);

    if (user_info[id].total_borrow_book == 0)
    {
        printf("This user have not borrowed any book.\n");
    }
    else 
    {
        printf("List borrowed book: \n");
        for (int i=0; i <= user_info[id].total_borrow_book ; i++)
        {
            if (user_info[id].list_borrowed[i].status == BORROWED)
            {
                printf("%d. ", i);
                print_infor_book(user_info[id].list_borrowed[i].id);
            }
        }
    }
}

static bool validate_user_id(int* id, e_user_menu_option_t mode)
{
    if ((*id <= 0) || (*id > MAX_USER))
    {
        printf("ID out range 1 - %d\n",MAX_USER);
        return ID_INVALID;
    }

    switch (mode)
    {
        case ADD_USER:
            if (user_info[*id].status != USER_BLANK_SLOT)
            {   
                printf("This ID belongs to another user. Please input another value\n");
                return ID_INVALID;
            }
            break;

        case EDIT_USER_INFO:
        case DELETE_USER:
        case UPDATE_BOOK_BORROW:
        case UPDATE_BOOK_RETURN:
            if (user_info[*id].status == USER_BLANK_SLOT)
            {
                printf("There is no user with this ID. Please input another value\n");
                return ID_INVALID;
            }

        default:
            break;
    }
    
    return ID_VALID ;
}

int input_user_id(e_user_menu_option_t mode)
{
    int temp_id = RESET_VALUE;
    do 
    {
        printf("ID: ");
        scanf("%d",&temp_id);
        getchar();
    }
    while(validate_user_id(&temp_id,mode));

    return temp_id;
}

void add_user(void)
{
    if(available_user <= MAX_USER)
    {
        printf("Please input user infomation: \n");

        int temp_id = input_user_id(ADD_USER);
        user_info[temp_id].id = temp_id;

        printf("Name: ");
        fgets(user_info[temp_id].name, MAX_CHARACTER, stdin);
        user_info[temp_id].name[strcspn(user_info[temp_id].name, "\n")] = '\0';

        user_info[temp_id].total_borrow_book = RESET_VALUE;

        user_info[temp_id].status = USER_USED_SLOT;

        printf("Added new user into library\n");
        print_infor_user(temp_id);
        available_user++;
    }
    else 
    {
        printf("Library is full. Cannot add new user.\n");
    }
}

void edit_user_info(void)
{
    if (display_user_infor())
    {
        printf("Please input the id user need to be edited: \n");
        int temp_id = input_user_id(EDIT_USER_INFO);

        printf("Current user information: \n");
        print_infor_user(temp_id);
        
        printf("Editing infor:\n");

        printf("Name: ");
        fgets(user_info[temp_id].name, MAX_CHARACTER, stdin);
        user_info[temp_id].name[strcspn(user_info[temp_id].name, "\n")] = '\0';

        printf("\nEdited. New information:\n");
        print_infor_user(temp_id);
    }
}

void delete_user(void)
{
    if (display_user_infor())
    {
        printf("Please input the id user need to be deleted: \n");
        int temp_id = input_user_id(DELETE_USER);

        printf("Deleting user below: \n");
        print_infor_user(temp_id);
        memset(&user_info[temp_id], RESET_VALUE, sizeof(user_info[temp_id]));

        printf("Deleted\n");
        available_user--;
    }
}

void user_management(void)
{
    int option;
    while(TRUE)
    {
        user_menu_print();
        scanf("%d",&option);
        switch(option)
        {
            case ADD_USER:
                add_user();
                break;

            case EDIT_USER_INFO:
                edit_user_info();
                break;

            case DELETE_USER:
                delete_user();
                break;

            case BACK_TO_MAIN:
                main_app();
                break;            

            default:
                break;
        }
    }
}