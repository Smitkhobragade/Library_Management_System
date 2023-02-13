#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sll.h"
#include "hash.h"

struct admin{
    int adid;
    int password;
    char adname[20];
};

int modeInput();
void initialize_lib(books **b);
int adminOptions(books **b);

/*
void displayBooks(books * b){
    /*books *temp = b;
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
    books * b = NULL;
    initialize_lib(&b);
    students * std[100] = NULL;             //a is hash table

    while(1)
    {
        int ch = modeInput();
        switch(ch)
        {
            case 1: adminOptions(&b);
                    break;
                
            case 2: studentOptions(&std,&b);
                    break;

            case 3: exit(1);

            default: printf("Invalid Choice!\n");
                    break;
        }
    }
    return 0;
}

int adminOptions(books **b)                // 1 for inserting book and 2 for printing data of books.
{                                          // 2 functions are specified here, if you want to add any other function in adminOptions than extend this cases :)
    int ch2;
    while(1)
    {
        printf("Enter admin op: ");
        scanf("%d",&ch2);
        switch(ch2)
        {
            case 1: insertAtEnd(b,1);
                    break;
                
            case 2: display(*b);
                    break;

            case 3: return 1;

            default: break;
        }
    }
    return 0;
}

void studentOptions(students *std, books *b)         // Active
{
    while(1)
    {
        int ch1;
        printf("Enter choice: ");
        scanf("%d",ch1);
        
        switch(ch2)
        {
            case 1: 
        }
    }
}

int modeInput()
{
    int i;
    printf("Enter 1 for Admin.\nEnter 2 for Student.\n");
    scanf("%d",&i);
    return i;
}

/* int studentOptions(struct students *s[])    // Incomplete
{
    int ch1;
    char name1[20];
    int id1;
    char bn[40];

    printf("Enter your Name: ");
    scanf("%s",name1);
    printf("Enter your ID no.: ");
    scanf("%d",&id1);
    printf("Enter 1 to issue book.\nEnter 2 to return book.\nEnter 3 to view fine.\n");
    scanf("%d",&ch1);

    switch(ch1)
    {
        case 1: printf("Enter book name: ");
                scanf("%s",bn);
                issueBookStd(s[],bn);
                break;

        case 2: returnBookStd();
                break;

        default: printf("Invalid Case!");
    }
}*/