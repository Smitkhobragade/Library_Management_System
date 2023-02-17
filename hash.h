#include <string.h>
#include <stdio.h>

typedef struct student
{
    int stdid;
    int issuedBooks[4];         // contains id of issued books
    char stdName[20];
    struct student *link;
} students;

void createS(students **head)
{
    *head = (students *)malloc(sizeof(students));
    if (*head == NULL)
        printf("Unable to insert stuedent's data.\n");
}

void addStd(students *a[], int id, char name[])
{
    int i = id % 100;

    students *newNode;
    createS(&newNode);

    newNode->stdid = id; // initialising node
    strcpy(newNode->stdName, name);
    newNode->link = NULL;
    for (int j = 0; j < 4; j++)
        newNode->issuedBooks[j] = 0;

    if (a[i] == NULL)
        a[i] = newNode;
    else
    {
        students *temp = a[i];
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

int removeStd(students *a[], int id)
{
    int i = id % capacity;
    if (a[i] == NULL)
    {
        printf("The student is not present in the system\n");
        return 0;
    }
    else
    {
        students *temp = a[i];
        while (temp->link->link != NULL)
        {
            if (temp->link->stdid == id)
                break;
            temp = temp->link;
        }
        if (temp->link->stdid == id)
        {
            temp->link = temp->link->link;
            return 1;
        }
        else
            return 0;
    }
}

students *StdExists(students *a[], int id)
{
    int i = id % capacity;

    students *temp = a[i];
    while (temp->link != NULL)
    {
        if (temp->stdid == id)
            break;
        temp = temp->link;
    }
    if (temp->stdid == id)
        return temp;
    else
        return NULL;
}

int issueBook(students *a[], books **b, int id, int bookid)
{
    students *temp = StdExists(a, id);
    if ((*b)->available == 0)
    {
        printf("These book in not available in the library to be issued!!!\n");
        return 0; // book is not available to be issued
    }
    if (temp != NULL)
    {
        int j = 0;
        while (temp->issuedBooks[j] != 0)
            j++;
        if (j > 3)
        {
            printf("You can only issue 4 books at a time.\n");
            return 2; // returns 2 if max limit is reached
        }
        else
        {
            temp->issuedBooks[j] = bookid;
            books *temp1 = *b;
            while (temp1 != NULL)
            {
                if (temp1->id == bookid)
                    break;
                temp1 = temp1->link;
            }
            if (temp1->id == bookid)
            {
                (temp1->available)--;
                (temp1->issued)++;
            }
            else
            {
                printf("Invalid Book ID, there is no such book available in library.\n");
                return 3;
            }
            printf("BOOK ISSUED!\n");
            return 1; // returns 1 if book is inserted
        }
    }
    else
    {
        printf("You are not enrolled in Library! Please, contact admin.\n");
        return 0; // returns 0 if Student is not in data
    }
}

int returnBook(students *a[], books **b, int id, int bookid)
{
    students *temp = StdExists(a, id);
    if (temp != NULL)
    {
        int j = 0;
        while (temp->issuedBooks[j] != 0)
        {
            if (temp->issuedBooks[j] == bookid)
                break;
            j++;
        }
        if (j <= 3)
        {
            if (temp->issuedBooks[j] != bookid)
            {
                printf("The user has not issued such a book\n");
                return 0; // returns 2 if the book is not present
            }
            else
            {
                while (j < 3)
                {
                    // temp->issuedBooks[j]=temp->issuedBooks[j+1];
                    temp->issuedBooks[j - 1] = temp->issuedBooks[j];
                    j++;
                }
                temp->issuedBooks[j] = 0;
                printf("BOOK RETURNED SUCCESSFULLY!\n");
                books *temp1 = *b;
                while (temp1 != NULL)
                {
                    if (temp1->id == bookid)
                        break;
                    temp1 = temp1->link;
                }
                if (temp1->id == bookid)
                {
                    (temp1->available)++;
                    (temp1->issued)--;
                }
                return 1; // returns 1 if book is present in data
            }
        }
    }
    else
        return 0;
}

void display_students(students *a[])
{
    for (int i = 0; i < capacity; i++)
    {
        students *temp = a[i];
        if (temp != NULL)
        {
            while (temp != NULL)
            {
                printf("\n--------- Student (ID %d) Data ---------\n",(temp->stdid));
                printf("Student Name : %s\n", temp->stdName);
                printf("Issued Books with ID : %d %d %d %d\n", temp->issuedBooks[0], temp->issuedBooks[1], temp->issuedBooks[2], temp->issuedBooks[3]);
                temp = temp->link;
            }
        }
    }
}

void mydata(students *a[], int myid)
{
    for (int i = 0; i < capacity; i++)
    {
        students *temp = a[i];
        if (temp != NULL)
        {
            while (temp != NULL)
            {
                if(temp->stdid == myid)
                {
                    printf("\n--------- %s's Data ---------\n",(temp->stdName));
                    printf("ID : %d\n", temp->stdid);
                    printf("Issued Books with ID : %d %d %d %d\n", temp->issuedBooks[0], temp->issuedBooks[1], temp->issuedBooks[2], temp->issuedBooks[3]);
                }
                temp = temp->link;
            }
        }
    }
}