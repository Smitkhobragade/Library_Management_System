#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "books.h"
#define capacity 100
#include "students.h"

struct admin
{
    int adid;
    int password;
    char adname[20];
};

int modeInput();
void initialize_lib(books **b);
int adminOptions(students *std[], books **b, int dates_a[]);
void initialize_std(students *a[]);
int studentOptions(students *std[], books **b);
int pay_fine(int d1, int m1, int y1, int d2, int m2, int y2);
int input_dates(int a[]);

int input_dates(int a[])
{
    printf("PLEASE INPUT ISSUE DATE\n");
    printf("ENTER DATE : ");
    scanf("%d", &a[0]);
    printf("ENTER MONTH : ");
    scanf("%d", &a[1]);
    printf("ENTER YEAR : ");
    scanf("%d", &a[2]);
    printf("PLEASE INPUT RETURN DATE\n");
    printf("ENTER DATE : ");
    scanf("%d", &a[3]);
    printf("ENTER MONTH : ");
    scanf("%d", &a[4]);
    printf("ENTER YEAR : ");
    scanf("%d", &a[5]);
}

int main()
{
    int dates_a[10];
    books *b = NULL;
    students *std[100];
    for (int j = 0; j < capacity; j++)
        std[j] = NULL;

    printf("\n\n");
    printf("****************************************\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*          WELCOME TO LIBRARY          *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("****************************************\n");
    printf("\n\n");
    int x;
    printf("Enter 1 to start library: ");
    scanf("%d", &x);
    if (x == 1)
    {
        printf("\nEnter 3 books info:\n\n");
        initialize_lib(&b);
        printf("\nStudent data inserted!\n\n");
        initialize_std(std);
    }
    // display_students(std);
    // pay_fine(25, 1, 2023, 4, 2, 2023);
    // pay_fine(1, 1, 2023, 1, 2, 2023);

    while (1)
    {
        int ch = modeInput();
        switch (ch)
        {
        case 1:
            adminOptions(std, &b, dates_a);
            break;

        case 2:
            studentOptions(std, &b);
            break;

        case 3:
            exit(1);

        default:
            printf("Invalid Choice!\n");
            break;
        }
    }
    return 0;
}

int adminOptions(students *std[], books **b, int dates_a[]) // 1 for inserting book and 2 for printing data of books and 3 for printing students data.
{                                                           // 2 functions are specified here, if you want to add any other function in adminOptions than extend this cases :)
    int ch2;
    while (1)
    {
        printf("\n\n****************** Admin Menu ********************\n");
        printf("*                                                *\n");
        printf("*           Enter 1 to add new book.             *\n");
        printf("*     Enter 2 to display data of all books.      *\n");
        printf("*     Enter 3 to display data of all students.   *\n");
        printf("*           Enter 4 to Calculate Fine            *\n");
        printf("*        Enter 5 to return to Main menu.         *\n");
        printf("*                                                *\n");
        printf("**************************************************\n");
        scanf("%d", &ch2);
        switch (ch2)
        {
        case 1:
            insertAtEnd(b, 1);
            break;

        case 2:
            display(*b);
            break;

        case 3:
            display_students(std);
            break;
        case 4:
            input_dates(dates_a);
            pay_fine(dates_a[0], dates_a[1], dates_a[2], dates_a[3], dates_a[4], dates_a[5]);
            break;
        case 5:
            return 1;

        default:
            break;
        }
    }
    return 0;
}

int studentOptions(students *std[], books **b)
{
    int stdid2, bid2;
    while (1)
    {
        int ch2;
        printf("\n\n************** Student Menu ****************\n");
        printf("*                                          *\n");
        printf("*          Enter 1 to issue book.          *\n");
        printf("*          Enter 2 to return book.         *\n");
        printf("*        Enter 3 to print your data.       *\n");
        printf("*       Enter 4 to return to Main menu.    *\n");
        printf("*                                          *\n");
        printf("********************************************\n");
        printf("Enter: ");
        scanf("%d", &ch2);

        switch (ch2)
        {
        case 1:
            printf("Enter your ID: "); // Issue Book
            scanf("%d", &stdid2);
            printf("Enter Book ID to be issued: ");
            scanf("%d", &bid2);
            issueBook(std, b, stdid2, bid2);
            break;

        case 2:
            printf("Enter your id: "); // Return Book
            scanf("%d", &stdid2);
            printf("Enter book id to be returned: ");
            scanf("%d", &bid2);
            returnBook(std, b, stdid2, bid2);
            break;

        case 3:
            printf("Enter your id: "); // Print data of student with specific ID.
            scanf("%d", &stdid2);
            mydata(std, stdid2);
            break;

        case 4:
            return 1;

        default:
            break;
        }
    }
}

int modeInput()
{
    int i;
    printf("\n\n******************** Main Menu ********************\n");
    printf("*                                                 *\n");
    printf("*             Enter 1 for Admin Panel.            *\n");
    printf("*            Enter 2 for Student Panel.           *\n");
    printf("*             Enter 3 to end program.             *\n");
    printf("*                                                 *\n");
    printf("***************************************************\n");
    printf("Enter: ");
    scanf("%d", &i);
    return i;
}

void initialize_std(students *a[])
{
    addStd(a, 56, "Sahil");
    addStd(a, 64, "Smit");
    addStd(a, 62, "Shreyash");
    addStd(a, 57, "Samrat");
    addStd(a, 58, "Sarang");
    addStd(a, 70, "Yash");
    addStd(a, 46, "Gaurav");
    addStd(a, 60, "Saurabh");
    addStd(a, 61, "Shreyansh");
    addStd(a, 51, "Poushik");
}

int pay_fine(int d1, int m1, int y1, int d2, int m2, int y2)
{

    m1 = (m1 + 9) % 12;
    y1 = y1 - m1 / 10;
    int x1 = 365 * y1 + y1 / 4 - y1 / 100 + y1 / 400 + (m1 * 306 + 5) / 10 + (d1 - 1);

    m2 = (m2 + 9) % 12;
    y2 = y2 - m2 / 10;
    int x2 = 365 * y2 + y2 / 4 - y2 / 100 + y2 / 400 + (m2 * 306 + 5) / 10 + (d2 - 1);
    if ((x2 - x1) < 15)
    {
        printf("---------- NO FINE ----------\n");
        return 0;
    }

    printf("----- Your Fine is : Rs. %d  -----\n", 2 * (x2 - x1 - 14));

    return 2 * (x2 - x1 - 14);
    // 14 days from book issue
}