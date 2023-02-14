#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sll.h"
#define capacity 100
#include "hash.h"

struct admin{
    int adid;
    int password;
    char adname[20];
};

int modeInput();
void initialize_lib(books **b);
int adminOptions(books **b);
void initialize_std(students *a[]);
int studentOptions(students *std[], books **b) ;        

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
    students * std[100];             //a is hash table
    initialize_lib(&b);
    initialize_std(std);

    while(1)
    {
        int ch = modeInput();
        switch(ch)
        {
            case 1: adminOptions(&b);
                    break;
                
            case 2: studentOptions(std,&b);
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
        printf("\n\n------------Admin Menu------------\nEnter operation no.: ");
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

int studentOptions(students *std[], books **b)         // Active
{
    int stdid2,bid2;
    while(1)
    {
        int ch2;
        printf("\n\n------------Student Menu------------\nEnter operation no.: ");
        scanf("%d",&ch2);
        
        switch(ch2)
        {
            case 1: printf("Enter your id: ");              // Issue Book
                    scanf("%d",&stdid2);
                    printf("Enter book id to be issued: ");
                    scanf("%d",&bid2);
                    issueBook(std,stdid2,bid2);
                    break;
                
            case 2: printf("Enter your id: ");              // Return Book
                    scanf("%d",&stdid2);
                    printf("Enter book id to be returned: ");
                    scanf("%d",&bid2);
                    returnBook(std,stdid2,bid2);
                    break;

            case 3: return 1;

            default: break;
        }
    }
}

int modeInput()
{
    int i;
    printf("\n\n------------Main Menu------------\nEnter 1 for Admin.\nEnter 2 for Student.\n");
    scanf("%d",&i);
    return i;
}

void initialize_std(students *a[])
{
    a[0] = NULL;

    addStd(a,56,"Sahil");
    addStd(a,64,"Smit");
    addStd(a,62,"Shreyash");
}