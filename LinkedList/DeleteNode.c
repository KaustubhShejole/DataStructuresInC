#include"InsertNode.h"
extern Node* Record_List;
Node* DeleteNode()
{
    printf("Please enter the passenger id whose all records needs to be deleted :");
    int temp;
    scanf("%d",&temp);
    char s[90];
    int flag;
    flag = 0;
    while(temp!=-1 && flag == 0)
    {
        while((give_pname(temp,s)==0) && (temp!=-1))
        {
            printf("Not Valid id please give other or enter -1 to exit");
            scanf("%d",&temp);
        }
        if(temp!=-1)
        {
            printf("%s\n",s);
            int j;
            printf("If it is your name enter 1 else 0: ");
            scanf("%d",&j);
            if(j==1)
            {
                flag = 1;
            }
            else
            {
                printf("Please enter your passenger id else to exit enter -1:");
                scanf("%d",&temp);
            }
        }
    }
    if (temp!=-1)
    {
        Node* nptr;
        Node* ptr;
        nptr=Record_List;
        ptr=nptr;
        if(nptr->data.pid==temp)
        {
            Record_List = Record_List->next;
            free(nptr);
        }
        while(nptr->next!=NULL)
        {
            if (nptr->next->data.pid == temp)
            {
                ptr=nptr->next;
                nptr->next = nptr->next->next;
                free(ptr);
            }
            if(nptr!=NULL)
            {
                nptr=nptr->next;
            }
        }
    }
    return Record_List;
}