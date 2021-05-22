//library management system

#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct details //to store all the details while creating a record
{
    char branchName[100];
    int bookId;
    int duration;
    int rollNumber;
    long long int mobileNumber;
    struct details *next; // to store the address of the next node
};
struct details *start = NULL;

struct details *createRecord();   //to create a new record whenever a new book is issued
struct details *deleteRecord();   //to delete a record whenever a book is returned
struct details *displayRecords(); //to see all the records
struct details *findRecord();     //to display the records for students [find the record according to the roll number ]

int search();          //to check if a book is already issued while creating a record
int noElementSearch(); //to check if a book is not issued[admin tries to delete record for a book not issued]
int noRollSearch();    //to check if student enters a roll number who has not issued any books

struct node
{
    char adminPassword[30]; //to store password
};
struct node *start2 = NULL;

struct node *changePassword(); //to change the administrator password

int total = 0; //to keep track of the total number of books issued [initially 0 ]

int main()
{
    int choice;             //to store choice in admin panel
    int option;             //to store choice at login page
    int studentRollNumber;  //to store student's roll number in student panel
    char password[30];      //to store the entered password
    struct node *pass_node; //pointer pointing to the node that contains the password

    pass_node = (struct node *)malloc(sizeof(struct node)); //creating a node for password
    strcpy(pass_node->adminPassword, "musab");             //default password ["musab"]

    printf("\n\t\t\t\t ====================================================\n");
    printf("\t\t\t\t              WELCOME TO CENTRAL LIBRARY            \n");
    printf("\t\t\t\t ====================================================\n\n");

    do
    {
    login:
        printf("\t\t\t\t\t _______________________________\n"); //login page
        printf("\t\t\t\t\t|             LOGIN             |\n");
        printf("\t\t\t\t\t|_______________________________|\n");
        printf("\t\t\t\t\t|     1- As an administrator    |\n");
        printf("\t\t\t\t\t|_______________________________|\n");
        printf("\t\t\t\t\t|     2- As a student           |\n");
        printf("\t\t\t\t\t|_______________________________|\n");
        printf("\t\t\t\t\t|     3- Exit                   |\n");
        printf("\t\t\t\t\t|_______________________________|\n");

        printf("\n\nEnter your option: ");
        scanf("%d", &option);

        switch (option)
        {

        case 1:
            system("cls"); // to clear the screen
            printf("\nEnter the password: ");
            scanf("%s", &password);

            if (strcmp(password, pass_node->adminPassword) == 0) // to check if the entered password is correct
            {
                system("cls");
                printf("\n\t\t\t\t     =================================\n");
                printf("\t\t\t\t                  WELCOME             \n");
                printf("\t\t\t\t     =================================\n");

                printf("\t\t\t\t _______________________________________\n"); //admin panel
                printf("\t\t\t\t|               MAIN MENU               |\n");
                printf("\t\t\t\t|_______________________________________|\n");
                printf("\t\t\t\t|     1-Create a record                 |\n");
                printf("\t\t\t\t|_______________________________________|\n");
                printf("\t\t\t\t|     2-Delete a record                 |\n");
                printf("\t\t\t\t|_______________________________________|\n");
                printf("\t\t\t\t|     3-Display all records             |\n");
                printf("\t\t\t\t|_______________________________________|\n");
                printf("\t\t\t\t|     4-Change password                 |\n");
                printf("\t\t\t\t|_______________________________________|\n");
                printf("\t\t\t\t|     5-Exit                            |\n");
                printf("\t\t\t\t|_______________________________________|\n");

                do
                {
                    printf("\n\nEnter your choice: ");
                    scanf("%d", &choice);
                    printf("\n");

                    switch (choice)
                    {
                    case 1:
                        start = createRecord();
                        break;

                    case 2:
                        start = deleteRecord();
                        break;

                    case 3:
                        start = displayRecords();
                        break;

                    case 4:
                        start2 = changePassword(pass_node);

                        if (strcmp(pass_node->adminPassword, "musab") != 0 || strcmp(pass_node->adminPassword, "musab") == 0)
                        {
                            goto login; //to take back to the login page when password is changed
                        }

                        break;

                    case 5:
                        system("cls");
                        break;

                    default:
                        printf("\nInvalid choice\n");
                    }

                } while (choice != 5);
            }
            else
            {
                system("cls");
                printf("Incorrect password\n");
            }

            break;

        case 2:
            system("cls");
            printf("\n\t\t\t\t\t  ===============================\n");
            printf("\t\t\t\t\t              WELCOME             \n");
            printf("\t\t\t\t\t  ===============================\n\n");

            printf("\t\t\t\t\t __________________________________\n"); //student panel
            printf("\t\t\t\t\t|     1- See all your records      |\n");
            printf("\t\t\t\t\t|__________________________________|\n");
            printf("\t\t\t\t\t|     2- Log out                   |\n");
            printf("\t\t\t\t\t|__________________________________|\n");

            do
            {
                printf("\n\nEnter your choice: ");
                scanf("%d", &studentRollNumber);
                switch (studentRollNumber)
                {
                case 1:
                    findRecord();
                    break;

                case 2:
                    system("cls");
                    break;

                default:
                    printf("\nInvalid choice\n");
                }

            } while (studentRollNumber != 2);

            break;

        case 3:
            break;

        default:
            system("cls");
            printf("\nInvalid choice\n");
        }

    } while (option != 3);
    return 0;
}

struct node *changePassword(struct node *pass_node)
{
    char oldPassword[30]; //to accept the old password

    printf("Enter the old password: ");
    scanf("%s", &oldPassword);

    if (strcmp(oldPassword, pass_node->adminPassword) == 0) //to check if entered password and old password match
    {
        printf("Enter the new password: ");
        scanf("%s", &pass_node->adminPassword); //password changed here
        system("cls");
        printf("\n* Password changed successfully.Please login again *\n\n");
    }
    else
    {
        system("cls");
        printf("Incorrect password :( Please login again\n");
    }

    return start2;
}

struct details *findRecord()
{
    struct details *ptr; //pointer used to traverse through the list
    int presentRoll;     //to store roll number of the student
    int invalidRoll;     //to store the result of the function *int noRollSearch()*

    printf("\n\nEnter your roll number: ");
    scanf("%d", &presentRoll);

    invalidRoll = noRollSearch(presentRoll);

    if (invalidRoll == 0)
    {
        printf("\n ** No records for this roll number **\n");
    }

    else
    {
        ptr = start;                               //to traverse from the start
        printf("\n\n\t\tBooks issued by you :\n"); //Menu columns
        printf("\t\t\t _______________________________________________________________________\n");
        printf("\t\t\t|  BOOK ID\t|   ISSUE DURATION   |\t ISSUE DATE   | Roll Number\t|\n");
        printf("\t\t\t|_______________|____________________|________________|_________________|\n");

        while (ptr != NULL) //to traverse through the whole list
        {
            if (ptr->rollNumber == presentRoll) //if roll number matches then print the data
            {
                printf("\t\t\t|%d\t        |   %d Days\t     |\t %s  | %d\t        |\n", ptr->bookId, ptr->duration, __DATE__, ptr->rollNumber);
                printf("\t\t\t|_______________|____________________|________________|_________________|\n");
            }
            ptr = ptr->next; //to move the pointer to the next node
        }
    }
}

int noRollSearch(int prRoll)
{
    struct details *ptr;

    ptr = start;
    while (ptr != NULL)
    {
        if (ptr->rollNumber == prRoll)
        {
            return -1;
        }
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        return 0; //Roll number not found after traversing through the list
    }
}

struct details *createRecord()
{
    struct details *new_node; //pointer to point to a new node
    struct details *ptr;      //to traverse and find the end of the list
    char branch[100];         //to store branch name
    int searchResult;         //to store the result of function *int search()*
    int bId;                  //to store book ID
    int dur;                  //to store duration
    int rollNo;               //to store roll number
    long long int mobileNo;   //to store mobile number

    new_node = (struct details *)malloc(sizeof(struct details)); //creating a new node in memory

    printf("Enter the book ID: ");
    scanf("%d", &bId);

    searchResult = search(bId);

    if (searchResult == bId)
    {
        printf("This book is not available(already issued)\n");
    }

    else
    {
        printf("Enter the branch: ");
        scanf("%s", &branch);
        printf("Enter the duration(Days): ");
        scanf("%d", &dur);
        printf("Enter full Roll number: ");
        scanf("%d", &rollNo);
        printf("Enter the Mobile number: ");
        scanf("%lld", &mobileNo);

        //transferring values to the node
        strcpy(new_node->branchName, branch);
        new_node->bookId = bId;
        new_node->duration = dur;
        new_node->rollNumber = rollNo;
        new_node->mobileNumber = mobileNo;

        if (start == NULL)
        {
            start = new_node;
            new_node->next = NULL;
        }

        else
        {
            ptr = start;

            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }

            ptr->next = new_node;
            new_node->next = NULL;
        }

        printf("\n\t\t***** Record Created! *****\n");

        total++; //increasing the counter for total books since a new book is issued
    }

    return start;
}

int search(int bId)
{
    struct details *ptr;
    ptr = start;

    if (start == NULL)
    {
        return -1;
    }

    else
    {

        while (ptr->next != NULL)
        {
            if (ptr->bookId == bId)
            {
                break;
            }
            ptr = ptr->next;
        }

        return ptr->bookId;
    }
}

struct details *deleteRecord()
{
    struct details *ptr;     //pointer to find the node which is to be deleted
    struct details *prePtr;  //pointer pointing to the node before the required node
    struct details *postPtr; //pointer pointing to the node after the required node
    int bId;                 //to store the ID of the book which is to be deleted
    int noBook;              //to store the result of the function *int noElementSearch()*

    ptr = start;
    if (start == NULL)
    {
        printf("\nThere is no book issued\n");
        return start;
    }

    printf("Enter the ID of the book to be removed: ");
    scanf("%d", &bId);

    noBook = noElementSearch(bId);

    if (noBook == total)
    {
        printf("\n ** Book ID not found(book is not issued) **\n");
    }

    else if (start->bookId == bId)
    {
        start = start->next;
        free(ptr); //freeing the node from memory
        printf("\n\t\t ***** Book returned successfully! *****\n");
        total--; //decreasing the counter for total books issued as a book is returned
    }

    else
    {

        while (ptr->bookId != bId) //until the required book ID is found
        {
            prePtr = ptr;        //prePtr remains behind ptr
            ptr = ptr->next;     //moving to the next node
            postPtr = ptr->next; //postPtr remains ahead of ptr
        }

        free(ptr);              //freeing the node
        prePtr->next = postPtr; //linking the node before the deleted node with the node after the deleted node
        printf("\n\t\t ***** Book returned successfully! *****\n");
        total--; //counter decreased by 1
    }

    return start;
}

int noElementSearch(int bId)
{
    struct details *ptr;

    ptr = start;
    while (ptr != NULL)
    {
        if (ptr->bookId == bId)
        {
            return -1;
        }
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        return total; //when book ID is not found after traversing the whole list
    }
}

struct details *displayRecords()
{
    struct details *ptr;

    if (start == NULL)
    {
        printf("\t** No records to display **\n");
    }

    else
    {
        ptr = start;

        //Menu columns
        printf("\t\t\t ________________________________________________________________________________________________________________\n");
        printf("\t\t\t|  BOOK ID\t|   ISSUE DURATION   |\t ISSUE DATE   |\t  Branch name   | Roll Number\t |\tMobile Number    |\n");
        printf("\t\t\t|_______________|____________________|________________|_________________|________________|_______________________|\n");

        while (ptr != NULL) //travelling to the last node
        {
            printf("\t\t\t|%d\t        |   %d Days\t     |\t %s  |  %s   \t| %d\t | %lld\t         |\n", ptr->bookId, ptr->duration, __DATE__, ptr->branchName, ptr->rollNumber, ptr->mobileNumber);
            printf("\t\t\t|_______________|____________________|________________|_________________|________________|_______________________|\n");

            ptr = ptr->next;
        }
    }

    printf("\n\t\t\t\t\t\t*******  Total number of books issued: %d  *******\n", total);

    return start;
}
