#include<string.h>
typedef struct student{
    int stdid;
    int issuedBooks[4]; //contains id of issued books
    char stdName[20];
    struct student * link;
}students;
void createS(students ** head){
    *head=(students *)malloc(sizeof(students));
    if(*head==NULL)
        printf("Cannot create nodeS\n");
    else    
        printf("NodeS created\n");
}
void addStd(students * a[], int id, char name[]){
    int i = id % capacity;
    students * newNode;
    createS( &newNode );

    newNode->stdid = id; //initialising node
    strcpy(newNode->stdName, name);
    newNode->link=NULL;
    for(int j=0;j<4;j++)
        newNode->issuedBooks[j]=0;

    if(a[i]==NULL)
        a[i]=newNode;
    else{
        students * temp= a[i];
        while(temp->link!=NULL)
            temp=temp->link;
        temp->link=newNode;
    }
}
int removeStd(students * a[], int id){
    int i = id % capacity;
    if(a[i]==NULL){
        printf("The student is not present in the system\n");
        return 0;
    }
    else{
        students * temp= a[i];
        while(temp->link->link!=NULL){
            if(temp->link->stdid == id)
                break;
            temp=temp->link;
        }
        if(temp->link->stdid == id){
            temp->link=temp->link->link;
            return 1;
        }
        else
            return 0;
    }
}
students * StdExists(students * a[] , int id){
    int i = id % capacity;
    students * temp = a[i];
    while(temp->link!=NULL){
            if(temp->stdid == id)
                break;
            temp=temp->link;
    }
    if(temp->stdid == id)
        return temp;
    else
        return NULL;
}
int issueBook(students * a[], int id, int bookid){
    students * temp=StdExists(a, id);
    if(temp != NULL){
        int j=0;
        while(temp->issuedBooks[j]!=0)
            j++;
        if(j>3)
            return 2; //returns 2 if max limit is reached
        else{
            temp->issuedBooks[j]=bookid;
            return 1; //returns 1 if book is inserted 
        }
    }
    else{
        return 0; //returns 0 if Student is not in data
    }
}
int returnBook(students * a[], int id, int bookid){
    students * temp=StdExists(a, id);
    if(temp != NULL){
            int j=0;
            while(temp->issuedBooks[j]!=0){
                if(temp->issuedBooks[j]==bookid)
                    break;
                j++;
            }
        if(j<=3){
            if(temp->issuedBooks[j]!=bookid)
                return 0;//returns 2 if the book is not present
            else{
                while(j<3){
                    temp->issuedBooks[j]=temp->issuedBooks[j+1];
                    j++;
                }
                temp->issuedBooks[j]=0;
                return 1; //returns 1 if book is present in data
            }
        }
    }
    else
        return 0;
}