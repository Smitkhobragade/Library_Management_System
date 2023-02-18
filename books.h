#include <stdio.h>
#include <stdlib.h>

typedef struct books
{
    int id;
    char bookName[40];
    int issued;
    int available;
    struct books *link;
} books;

// for initailse lib function
void createNode1(books **head1)
{
    *head1 = (books *)malloc(sizeof(books));
    if (*head1 == NULL)
        printf("Cannot create BOOK\n");
}

// for inititalising lib finction
books * insertAtEnd1(books **head,int bookid)
{
    books *newNode;
    createNode1(&newNode);
    if (newNode == NULL)
    {
        printf("Cannot insert the BOOK at end\n");
    }
    else
        printf("BOOK inserted at end\n");

    newNode->id=bookid;
    newNode->link = NULL;

    books *temp;
    temp = *head;
    if (temp == NULL)
    {
        *head = newNode;
    }
    else
    {
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newNode;
    }
    return newNode;
}

int isEmpty(books *head)
{
    if (head == NULL)
        return 1;
    return 0;
}

void initialize_lib1(books ** ptr){
    books *newNode;

    newNode=insertAtEnd1(ptr,101);//Book 1
    strcpy(newNode->bookName, "Mathematics");
    newNode->available = 4;

    newNode=insertAtEnd1(ptr,102);// Book 2
    strcpy(newNode->bookName, "Life");
    newNode->available = 6;

    newNode=insertAtEnd1(ptr,103);// Book 3
    strcpy(newNode->bookName, "Pschychology");
    newNode->available = 9;

    newNode=insertAtEnd1(ptr,104);// Book 4
    strcpy(newNode->bookName, "Basic_C");
    newNode->available = 4;

    newNode=insertAtEnd1(ptr,105);// Book 5
    strcpy(newNode->bookName, "Logic_design");
    newNode->available = 8;
}

void display(books *head)
{
    if (isEmpty(head))
        printf("The LIST is Empty\n");
    else
    {
        printf("\nBOOKS DATA :  \n");
        while (head != NULL)
        {
            printf("\n----------- BOOK -----------\n");
            printf("Book ID is : %d \n", head->id);
            printf("Book name : %s \n", head->bookName);
            printf("Available no. of books : %d \n", head->available);
            printf("Books issued : %d", head->issued);
            head = head->link;
            printf("\n----------------------------\n");
        }
        printf("\n");
    }
}

void input_data(books **head1)
{
    printf("Enter Book ID : ");
    scanf("%d", &((*head1)->id));
    printf("Enter Book Name : ");
    scanf("%s", &((*head1)->bookName));
    printf("Enter available books : ");
    scanf("%d", &((*head1)->available));
    ((*head1)->issued) = 0;
}

void createNode(books **head1)
{
    *head1 = (books *)malloc(sizeof(books));
    if (*head1 == NULL)
        printf("Cannot create BOOK\n");
    else
    {
        printf("BOOK created\n");
        input_data(head1);
    }
}

void insertAtEnd(books **head)
{
    books *newNode;
    createNode(&newNode);
    if (newNode == NULL)
    {
        printf("Cannot insert the BOOK at end\n");
    }
    else
        printf("Book inserted.\n\n");
    newNode->link = NULL;

    books *temp;
    temp = *head;
    if (temp == NULL)
    {
        *head = newNode;
    }
    else
    {
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}