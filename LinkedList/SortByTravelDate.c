#include"InsertNode.h"
extern Node* Record_List;

typedef struct P_Node_tag
{
    int dstat_num;
    date d;
    struct P_Node_tag* next;
}P_Node;
Boolean is_smaller_date(date d1,date d2)
{
    //returns TRUE if d1<d2
    Boolean ret_val;
    ret_val = FALSE;
    if(d1.yy<d2.yy)
    {
        ret_val = TRUE;
    }
    else if(d2.yy == d1.yy)
    {
        if(d1.mm<d2.mm)
        {
            ret_val = TRUE;
        }
        else if(d1.mm==d2.mm)
        {
            if(d1.dd<=d2.dd)
            {
                ret_val = TRUE;
            }
        }
    }
    return ret_val;
}
P_Node* InsertAtPEND(P_Node* nptr,P_Node* lptr)
{
    if(lptr==NULL)
    {
        lptr=nptr;
        lptr->next=NULL;
    }
    else
    {
        P_Node* temp_ptr;
        temp_ptr=lptr;
        if(temp_ptr->next==NULL)
        {
            if(is_smaller_date(nptr->d, temp_ptr->d))
            {
                lptr=nptr;
                nptr->next = temp_ptr;
                temp_ptr->next=NULL;
            }
            else
            {
                temp_ptr->next = nptr;
                nptr->next=NULL;
            }
        }
        else
        {
            if(is_smaller_date(nptr->d, temp_ptr->d))
            {
                if(temp_ptr==lptr)
                {
                    lptr=nptr;
                    nptr->next = temp_ptr;
                }
            }
            else
            {
                while(temp_ptr->next!=NULL && !(is_smaller_date(nptr->d,temp_ptr->next->d)))
                {
                    temp_ptr=temp_ptr->next;
                }
                nptr->next = temp_ptr->next;
                temp_ptr->next = nptr;
            }
        }       
    }
    return lptr;
}
void DeletePList(P_Node* p)
{
    P_Node* temp_ptr;
    temp_ptr=p;
    while(temp_ptr!=NULL)
    {
        p = p->next;
        free(temp_ptr);
        temp_ptr=p;
    }
}
void DisplayPList(P_Node* lptr)
{
    P_Node* temp_ptr;
    temp_ptr=lptr;
    while(temp_ptr!=NULL)
    {
        printf("Destination Station : %s with station id %d on ",station_array[temp_ptr->dstat_num-1].data.name,temp_ptr->dstat_num);
        print_date(temp_ptr->d);
        temp_ptr=temp_ptr->next;
    }
}
void SortByTravelDate()
{
    P_Node* zlptr;
    zlptr=NULL;
    P_Node* ptr;
    ptr=NULL;
    Node* nptr;
    nptr = Record_List;
    printf("Please enter the passenger id to get destination stations as per dates of travel: ");
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
        nptr=Record_List;
        while(nptr!=NULL)
        {
            if (nptr->data.pid == temp)
            {
                ptr=(P_Node*)malloc(sizeof(P_Node));
                ptr->dstat_num = nptr->data.dstat_num;
                date_cpy(&ptr->d,&nptr->data.d);
                ptr->next=NULL;
                zlptr=InsertAtPEND(ptr,zlptr);
            }
            nptr=nptr->next;
        }
    }
    DisplayPList(zlptr);
    DeletePList(zlptr);
}