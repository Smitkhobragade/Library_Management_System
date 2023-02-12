#include<stdio.h>

struct books{
    int id;
    char bookName[40];
    int issued;
    int available;
};

struct students{
    int stdid;
    int issuedBooks[4];
    char stdName[20];
};

struct admin{
    int adid;
    int password;
    char adname[20];
};

int modeInput();

int main()
{
    struct books b[5];
    b[0].id=1; b[0].bookName="brfvn"; b[0].issued=0; b[0].available=10;
    b[1].id=2; b[1].bookName="drfgthh"; b[1].issued=0; b[1].available=10;
    b[2].id=3; b[2].bookName="hiopfsw"; b[2].issued=0; b[2].available=10;
    b[3].id=4; b[3].bookName="nmjtex"; b[3].issued=0; b[3].available=10;
    b[4].id=5; b[4].bookName="giiuscn"; b[4].issued=0; b[4].available=10;
    
    struct students s[100];

    int ch = modeInput();
    switch(ch)
    {
        case 1: adminOptions();
                break;
            
        case 2: studentOptions(&s);
                break;

        default: printf("Invalid Choice!\n");
    }

    return 0;
}

int modeInput()
{
    int i;
    printf("Enter 1 for Admin.\nEnter 2 for Student.\n");
    scanf("%d",&i);
    return i;
}

int adminOptions()              // Incomplete
{

}

int studentOptions(struct students *s[])    // Incomplete
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
}