#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sll.h"
#define capacity 100
#include "hash.h"

struct admin
{
    int adid;
    int password;
    char adname[20];
};

int modeInput();
void initialize_lib(books **b);
int adminOptions(students *std[], books **b);
void initialize_std(students *a[]);
int studentOptions(students *std[], books **b);
int pay_fine(int d1, int m1, int y1, int d2, int m2, int y2);

/*
void displayBooks(books * b){
    books *temp = b;
    while(temp != NULL){
        printf("%d\n",temp->id);
        temp = temp->next;
    }
    books *ptr;
    ptr = b;
            while(ptr!=NULL){
            printf("\n\t_________________________________________________\n");
            // printf("\n\t Book %d",i);
            // printf("\n\t Book Title: %s",ptr->name);
            // printf("\n\t Name of Author: %s",ptr->author);
            printf("\n\t Book ID: %d",ptr->id);
            printf("\n\t_________________________________________________\n");
            ptr=ptr->next;
            // i++;
        }
}*/

/*void displaystdinfo(students *s)

*/

int main()
{
    books *b = NULL;
    students *std[100];
    for (int j = 0; j < capacity; j++)
        std[j] = NULL; // a is hash table
    // initialize_lib(&b);
    initialize_std(std);
    // display_students(std);
    pay_fine(25, 1, 2023, 4, 2, 2023);
    pay_fine(1, 1, 2023, 1, 2, 2023);

    while (1)
    {
        int ch = modeInput();
        switch (ch)
        {
        case 1:
            adminOptions(std, &b);
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

int adminOptions(students *std[], books **b) // 1 for inserting book and 2 for printing data of books.
{                                            // 2 functions are specified here, if you want to add any other function in adminOptions than extend this cases :)
    int ch2;
    while (1)
    {
        printf("\n\n------------Admin Menu------------\nEnter operation no.: ");
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
            return 0;

        default:
            break;
        }
    }
    return 0;
}

int studentOptions(students *std[], books **b) // Active
{
    int stdid2, bid2;
    while (1)
    {
        int ch2;
        printf("\n\n------------Student Menu------------\nEnter operation no.: ");
        scanf("%d", &ch2);

        switch (ch2)
        {
        case 1:
            printf("Enter your id: "); // Issue Book
            scanf("%d", &stdid2);
            printf("Enter book id to be issued: ");
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
            return 1;

        default:
            break;
        }
    }
}

int modeInput()
{
    int i;
    printf("\n\n------------Main Menu------------\nEnter 1 for Admin.\nEnter 2 for Student.\n");
    scanf("%d", &i);
    return i;
}

void initialize_std(students *a[])
{
    // a[0] = NULL;

    addStd(a, 56, "Sahil");
    addStd(a, 64, "Smit");
    addStd(a, 62, "Shreyash");
    addStd(a, 156, "XYZ");
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
        printf("NO FINE \n");
        return 0;
    }

    printf("Your Fine is : %d \n", 2 * (x2 - x1 - 14));

    return 2 * (x2 - x1 - 14);
    // 14 days from book issue
}