typedef struct books
{
    int id;
    char bookName[40];
    int data;
    int issued;
    int available;
    struct books *link;
} books;

// for initailse lib function
void createNode1(books **head1)
{
    *head1 = (books *)malloc(sizeof(books));
    if (*head1 == NULL)
        printf("Cannot create node\n");
    else
    {
        // printf("Node created\n");
        // input_data(head1);
    }
}

// for inititalising lib finction
void insertAtEnd1(books **head, int d)
{
    books *newNode;
    createNode1(&newNode);
    if (newNode == NULL)
    {
        printf("Cannot insert the element at end\n");
    }
    else
        printf("Node inserted at end\n");
    newNode->data = d;
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

int isEmpty(books *head)
{
    if (head == NULL)
        return 1;
    return 0;
}

// void initialize_lib(books ** ptr){
//     books * head ;
//     head = *ptr;
//     insertAtEnd1(ptr,1);//Book 1
//     head = *ptr;
//     (head)->id = 10;
//     strcpy((head)->bookName, "QWERTY");
//     (head)->available = 4;

//     insertAtEnd1(ptr,2);// Book 2
//      head = *ptr;
//     (head)->id = 31;
//     strcpy((head)->bookName, "ASDFG");
//     (head)->available = 6;

//     insertAtEnd1(ptr,3);// Book 3
//      head = *ptr;
//     (head)->id = 15;
//     strcpy((head)->bookName, "ZXCVB");
//     (head)->available = 9;

//     insertAtEnd1(ptr,4);// Book 4
//      head = *ptr;
//     (head)->id = 12;
//     strcpy((head)->bookName, "POIUY");
//     (head)->available = 4;

//     insertAtEnd1(ptr,5);// Book 5
//      head = *ptr;
//     (head)->id = 3;
//     strcpy((head)->bookName, "MNBVC");
//     (head)->available = 8;
//     // *head = *ptr;
// }

void display(books *head)
{
    if (isEmpty(head))
        printf("The SLL is Empty\n");
    else
    {
        printf("\nBOOKS DATA :  ");
        while (head != NULL)
        {
            printf("\n----------BOOK -------------\n");
            printf("ID is : --> %d \n", head->id);
            printf("Book name --> %s \n", head->bookName);
            printf("books available --> %d \n", head->available);
            printf("Books issued: %d", head->issued);
            head = head->link;
            printf("\n----------------------------\n");
        }
        printf("\n");
    }
}

void input_data(books **head1)
{
    printf("Enter ID : ");
    scanf("%d", &((*head1)->id));
    printf("ENTER Name of Book : ");
    scanf("%s", &((*head1)->bookName));
    printf("Enter available books : ");
    scanf("%d", &((*head1)->available));
    ((*head1)->issued) = 0;
}

void createNode(books **head1)
{
    *head1 = (books *)malloc(sizeof(books));
    if (*head1 == NULL)
        printf("Cannot create node\n");
    else
    {
        printf("Node created\n");
        input_data(head1);
    }
}

void insertAtEnd(books **head, int d)
{
    books *newNode;
    createNode(&newNode);
    if (newNode == NULL)
    {
        printf("Cannot insert the element at end\n");
    }
    else
        printf("Book inserted.\n\n");
    newNode->data = d;
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

// Alternate void initialize_lib(books ** ptr)
void initialize_lib(books **ptr)
{
    for (int i = 0; i < 3; i++)
    {
        insertAtEnd(ptr, 1);
    }
}

void insertAtBeg(books **head, int d)
{
    books *newNode;
    createNode(&newNode);
    if (newNode == NULL)
    {
        printf("Cannot insert the element at beginning\n");
    }
    else
        printf("Node inserted at beginning\n");
    newNode->link = *head;
    *head = newNode;
    newNode->data = d;
}
int deletefirst(books **head)
{
    int temp;
    books *temp1 = *head;
    if (isEmpty(*head))
    {
        printf("No elements in sll to delete\n");
        temp = -999;
    }
    else
    {
        temp = temp1->data;
        *head = temp1->link;
    }
    free(temp1);
    return temp;
}
int deletelast(books **head)
{
    int t;
    books *temp = *head, *temp1;
    if (isEmpty(*head))
    {
        printf("No elements in sll to delete\n");
        t = -999;
    }
    else if (temp->link == NULL)
    {
        *head = NULL;
    }
    else
    {
        while (temp->link->link != NULL)
        {
            temp = temp->link;
        }
        t = temp->link->data;
        temp1 = temp->link;
        temp->link = NULL;
        free(temp1);
    }
    return t;
}
int length(struct books *head)
{
    struct books *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->link;
        count++;
    }
    return count;
}
void insertAtpos(struct books **head, int key, int pos)
{
    books *temp = *head;
    books *newNode;
    createNode(&newNode);
    newNode->data = key;
    if (pos == 1)
    {
        newNode->link = *head;
        *head = newNode;
    }
    else if (pos > 1 && pos <= length(*head))
    {
        int count = pos - 2;
        while (count--)
        {
            temp = temp->link;
        }
        newNode->link = temp->link;
        temp->link = newNode;
    }
    else
        printf("INVALID position\n");
}
int deletepos(books **head, int pos)
{
    books *temp = *head, *temp1;
    int a;
    if (pos == 1)
    {
        a = deletefirst(head);
    }
    else if (pos > 1 && pos < length(*head))
    {
        int count = pos - 2;
        while (count--)
        {
            temp = temp->link;
        }
        temp1 = temp->link;
        a = temp->link->data;
        temp->link = temp->link->link;
        free(temp1);
    }
    else
        printf("Invalid position entered\n");
    return a;
}
void reverse(books **head)
{
    books *rev, *ptr1, *ptr2;
    if (length(*head) > 1)
    {
        rev = *head;
        ptr1 = rev->link;
        ptr2 = ptr1->link;
        rev->link = NULL;
        while (ptr2 != NULL)
        {
            ptr1->link = rev;
            rev = ptr1;
            ptr1 = ptr2;
            ptr2 = ptr2->link;
            ptr1->link = rev;
        }
        ptr1->link = rev;
        *head = ptr1;
    }
}
int search(books **head, int key)
{
    books *temp = *head;
    int pos = 0;
    while (temp != NULL)
    {
        pos++;
        if (temp->data == key)
        {
            return pos;
        }
        temp = temp->link;
    }
    return -999;
}