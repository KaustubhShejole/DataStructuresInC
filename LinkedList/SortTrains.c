/*SortTrains
    • I/p parameters: The train database that is the linked list with passenger data as 
    given
    • O/p: Display the train number and the travel date in the sorted order of number 
    of passengers on the train.*/
#include"InsertNode.h"
extern Node* Record_List;
typedef struct Z_Node_tag
{
    int train_number;
    date d;
    int num_passengers;
    struct Z_Node_tag* next;
}Z_Node;
void date_cpy(date* d1,date* d2)
{
    d1->dd = d2->dd;
    d1->mm = d2->mm;
    d1->yy = d2->yy;
}
Boolean is_equal_date(date d1,date d2)
{
    Boolean ret_val;
    ret_val = FALSE;
    if(d1.dd==d2.dd && d1.mm==d2.mm && d1.yy==d2.yy)
    {
        ret_val = TRUE;
    }
    return ret_val;
}
Z_Node* InsertAtEND(Z_Node* nptr,Z_Node* lptr)
{
    if(lptr==NULL)
    {
        lptr=nptr;
        lptr->next=NULL;
    }
    else
    {
        Z_Node* temp_ptr;
        temp_ptr=lptr;
        if(temp_ptr->next==NULL)
        {
            if(nptr->num_passengers > temp_ptr->num_passengers)
            {
                //printf("greater\n");
                lptr=nptr;
                nptr->next = temp_ptr;
            }
            else
            {
                temp_ptr->next = nptr;
                nptr->next=NULL;
            }
        }
        else
        {
            if(nptr->num_passengers > temp_ptr->num_passengers)
            {
                if(temp_ptr==lptr)
                {
                    lptr=nptr;
                    nptr->next = temp_ptr;
                }
            }
            else
            {
                while(temp_ptr->next!=NULL && nptr->num_passengers<=temp_ptr->next->num_passengers)
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
void DisplayZList(Z_Node* lptr)
{
    Z_Node* temp_ptr;
    temp_ptr=lptr;
    while(temp_ptr!=NULL)
    {
        printf("%d train_id with %d passengers with ",temp_ptr->train_number,temp_ptr->num_passengers);
        print_date(temp_ptr->d);
        temp_ptr=temp_ptr->next;
    }
}
void DeleteZList(Z_Node* p)
{
    Z_Node* temp_ptr;
    temp_ptr=p;
    while(temp_ptr!=NULL)
    {
        p = p->next;
        free(temp_ptr);
        temp_ptr=p;
    }
}
void SortTrains()
{
    Z_Node* znode;
    znode=NULL;
    Node* nptr;
    nptr = Record_List;
    date d;
    d = nptr->data.d;
    int tnum;
    tnum = nptr->data.train_id;
    int nump;
    nump = 0;
    Z_Node* p;
    p=NULL;
    int i;
    i=0;
    while(nptr != NULL)
    {
        znode = (Z_Node*)malloc(sizeof(Z_Node));
        date_cpy(&(znode->d),&(nptr->data.d));
        znode->train_number = tnum; 
        while(nptr!=NULL && is_equal_date(d,nptr->data.d) && tnum==nptr->data.train_id)
        {
            nptr=nptr->next;
            nump++;
        }
        znode->num_passengers = nump;
        if(nptr!=NULL)
        {
            date_cpy(&d,&nptr->data.d);
            tnum = nptr->data.train_id;
        }
        i++;
        znode->next=NULL;
        nump=0;
        p = InsertAtEND(znode,p);
    }
    DisplayZList(p);
    DeleteZList(p);
}
/*int main()
{
    StoreStations();
	StoreTrains();
    StoreRecords();
    SortTrains();
    return 0;
}*/