typedef struct books{
    int id;
    char bookName[40];
    int issued;
    int available;
    books *link;
}books;

}books;

int isEmpty(struct node *head){
    if(head==NULL)
        return 1;
    return 0;
}
void display(struct node * head){
    if(isEmpty(head))
        printf("The SLL is Empty\n");
    else{
        printf("SLL :  ");
        while(head!=NULL){
            printf("%d ",head->data);
            head=head->link;
        }
        printf("\n");
    }
}
void createNode(struct node ** head1){
    *head1=(struct node *)malloc(sizeof(struct node));
    if(*head1==NULL)
        printf("Cannot create node\n");
    else    
        printf("Node created\n");
}
void insertAtEnd(struct node** head,int d){
    struct node * newNode;
    createNode(&newNode);
    if(newNode==NULL){
        printf("Cannot insert the element at end\n");
    }
    else
        printf("Node inserted at end\n");
    newNode->data=d;
    newNode->link=NULL;
    
    struct node * temp;
    temp= *head;
    if(temp==NULL){
        *head=newNode;
    }
    else{
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=newNode;
    }
}
void insertAtBeg(struct node ** head,int d){
    struct node * newNode;
    createNode(&newNode);
    if(newNode==NULL){
        printf("Cannot insert the element at beginning\n");
    }
    else
        printf("Node inserted at beginning\n");
    newNode->link=*head;
    *head=newNode;
    newNode->data=d;
}
int deletefirst(struct node ** head){
    int temp;
    struct node *temp1=*head;
    if(isEmpty(*head)){
        printf("No elements in sll to delete\n");
        temp=-999;
    }
    else {
        temp=temp1->data;
        *head=temp1->link;
    }
    free(temp1);
    return temp;
}
int deletelast(struct node **head){
    int t;
    struct node *temp=*head,*temp1;
    if(isEmpty(*head)){
        printf("No elements in sll to delete\n");
        t=-999;
    }
    else if(temp->link==NULL){
        *head=NULL;
    }
    else{
        while(temp->link->link!=NULL){
            temp=temp->link;
        }
        t=temp->link->data;
        temp1=temp->link;
        temp->link=NULL;
        free(temp1);
    }
    return t;
}
int length(struct node * head){
    struct node *temp=head;
    int count=0;
    while(temp!=NULL){
        temp=temp->link;
        count++;
    }
    return count;
}
void insertAtpos(struct node **head,int key,int pos){
    struct node *temp= *head;
    struct node *newNode;
    createNode(&newNode);
    newNode->data=key;
    if(pos==1){
        newNode->link=*head;
        *head=newNode;
    }
    else if(pos>1 && pos<=length(*head)){
        int count=pos-2;
        while(count--){
            temp=temp->link;
        }
        newNode->link=temp->link;
        temp->link=newNode;
    }
    else
        printf("INVALID position\n");
}
int deletepos(struct node ** head,int pos){
    struct node * temp= * head, *temp1;
    int a;
    if(pos==1){
       a = deletefirst(head);
    }
    else if(pos>1 && pos<length(*head)){
        int count=pos-2;
        while(count--){
            temp=temp->link;
        }
        temp1=temp->link;
        a=temp->link->data;
        temp->link=temp->link->link;
        free(temp1);
    }
    else
        printf("Invalid position entered\n");
    return a;
}
void reverse(struct node ** head){
    struct node *rev, *ptr1, *ptr2;
    if(length(*head)>1){
        rev=*head;
        ptr1=rev->link;
        ptr2=ptr1->link;
        rev->link=NULL;
        while(ptr2!=NULL){
            ptr1->link=rev;
            rev=ptr1;
            ptr1=ptr2;
            ptr2=ptr2->link;
            ptr1->link=rev;
        }
        ptr1->link=rev;
        *head=ptr1;
    }
}
int search(struct node **head, int key){
    struct node *temp=*head;
    int pos=0;
    while(temp!=NULL){
        pos++;
        if(temp->data==key){
            return pos;
        }
        temp=temp->link;
    }
    return -999;
}
// void main(){

// }