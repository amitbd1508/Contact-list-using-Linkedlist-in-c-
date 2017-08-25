#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node
{
    char  number[50];
    char  name[50];

    struct node* next;
};
struct node* head=NULL;
FILE *fp,*wfp;
bool searching(char value[])
{
    node *current;
    current=head;
    while(current!=NULL)
    {
        if(strcmp(current->number,value)==0)
        {
            puts(current->name);
            puts(current->number);
            return true;
        }
        current=current->next;
    }
    return false;
}
void insert(char *name,char  *number)
{
    struct node* element;
    element = new struct node;
    strcpy(element->name,name);
    strcpy(element->number,number);
    element->next = NULL;

    if(head==NULL)
    {
        head = element;
    }
    else
    {
        struct node* current;
        for(current=head;current->next!=NULL;current=current->next);

        current->next = element;
    }
}
void print()
{
    struct node* current;
    for(current=head;current!=NULL;current=current->next)
    {
        puts(current->name);
        puts(current->number);
        puts("\n");
    }
    printf("\n");
}
void remove(char *value)
{
    struct node *current,*prev;
    prev=NULL;
    for(current=head;current->next!=NULL;current=current->next)
    {
        if(strcmp(current->number,value)==0)
            break;
        prev = current;

    }
    if(prev==NULL)
    {
        head = current->next;
    }
    else
    {
            prev->next = current->next;
    }
    free(current);
}

bool modify(char *name,char *number,char value[])
{
    node *current;
    current=head;
    while(current!=NULL)
    {
        if(strcmp(current->number,value)==0)
        {
            strcpy(current->name,name);
            strcpy(current->number,number);
            return true;
        }
        current=current->next;
    }
    return false;
}
int main()
{
    fp=fopen("phonebook.txt","r");

    while(1){
    printf("<===============Phone-Book Menu============>\n");
    printf("Enter 1 for Add a phone number\n");
    printf("Enter 2 for Delete a phone number\n");
    printf("Enter 3 for Modify a phone number\n");
    printf("Enter 4 for Search a phone number\n");
    printf("Enter 5 for print a deatils\n");
    printf("Enter 0 for Exit a phone number\n");

    int cas;
    scanf("%d",&cas);
    getchar();
    char name[50],number[50],temp[50];



        switch(cas)
        {
        case 1:
            printf("Please enter your contact name :");


            scanf("%s",name);
            printf("\nPlease enter your contact number :");
            scanf("%s",number);
            insert(name,number);
            printf("\nSucsessfully insterted\n");
            break;

        case 2:
            printf("\nEnter number for delete: ");

            scanf("%s",temp);
            remove(temp);
            printf("\nSucsessfully deleted\n");

            break;
        case 3:
             printf("\nEnter number for modify: ");

            scanf("%s",temp);
            printf("Please enter your contact name :");


            scanf("%s",name);
            printf("\nPlease enter your contact number :");
            scanf("%s",number);

            if(modify(name,number,temp))
                printf("\nSucsessfully modify\n");
            printf("\nUnsucsessfully modify\n");


            break;
        case 4:
            printf("\nEnter number for remove: ");
            scanf("%s",temp);
            if(!searching(temp))
                printf("contact not found");
            break;
        case 5:
            print();
            break;
        case 0:
            exit(0);
            break;

        }

    }
    return 0;
}
