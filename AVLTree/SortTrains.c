/*SortTrains
    • I/p parameters: The train database with passenger data as 
    given
    • O/p: Display the train number and the travel date in the sorted order of number 
    of passengers on the train.*/
#include"Insertion.h"
extern Tree_Node* Record_Root;
typedef struct Z_Node_tag
{
    int train_number;
    date d;
    int num_passengers;
    struct Z_Node_tag* next;
}Z_Node;
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
typedef struct Date_tag
{
    date data;
    struct Date_tag* next;
}Date;

Date* InsertAtdateEnd(Date* dptr,Date* nptr)
{
    if(dptr==NULL)
    {
        dptr=nptr;
        dptr->next=NULL;
    }
    else if (compare_date(dptr->data,nptr->data)==1)
    {
        nptr->next=dptr;
        dptr=nptr;
    }
    else
    {
        Date* prev;
        prev=dptr;
        Date* next;
        next= dptr->next;
        int done;
        done=0;
        while(next!=NULL && !done )
        {
            if(compare_date(next->data,nptr->data)==1 )
            {
                prev->next=nptr;
                nptr->next=next;
                done=1;
            }
            else if(compare_date(next->data,nptr->data)==0)
            {
                free(nptr);
                nptr=NULL;
                done=1;
            }
            else
            {
                prev = next;
                next=next->next;
            }
        }
    }
    return dptr;
}
Date* ExtractDates(Node* lptr,Date* dptr)
{
    Node* nptr;
    nptr=lptr;
    if(nptr != NULL)
    {
        Date* date_node;
        date_node = (Date*)malloc(sizeof(Date));
        date_node->next=NULL;
        date_cpy(&(date_node->data),&(nptr->data.d));
        date d;
        d = date_node->data;
        while(nptr!=NULL)
        {
            if(is_equal_date(d,nptr->data.d))
            {
                nptr=nptr->next;
            }
            else if (nptr!=NULL)
            {
                dptr=InsertAtdateEnd(dptr,date_node);
                date_node = (Date*)malloc(sizeof(Date));
                date_cpy(&(date_node->data),&(nptr->data.d));
                nptr=nptr->next;             
            }
            if (nptr==NULL)
            {
                dptr=InsertAtdateEnd(dptr,date_node);
            }
            
        }
    }
    return dptr;
}
Z_Node* fun(Node* lptr,date d,Z_Node* p)
{
    Node* nptr;
    nptr=lptr;
    if(nptr != NULL)
    {
        int nump;
        nump=0;
        Z_Node* znode;
        znode = (Z_Node*)malloc(sizeof(Z_Node));
        date_cpy(&(znode->d),&d);
        znode->train_number = nptr->data.train_id; 
        while(nptr!=NULL)
        {
            if(is_equal_date(d,nptr->data.d))
            {
                nump++;
            }
            nptr=nptr->next;
        }
        znode->num_passengers = nump;
        znode->next = NULL;
        p = InsertAtEND(znode,p);
    }
    return p;
}
Z_Node* Give_records(Node* lptr,Z_Node* p)
{
    Date* date_node;
    date_node=NULL;
    date_node = ExtractDates(lptr,date_node);
    Date* n_date;
    n_date=date_node;
    while(n_date!=NULL)
    {
        date_node=date_node->next;
        p = fun(lptr,n_date->data,p);
        free(n_date);
        n_date = date_node;
    }
    return p;
}
Z_Node* SortTrainsHelper(Tree_Node* root,Z_Node* p)
{
    if(root!=NULL)
    {
        p=SortTrainsHelper(root->left,p);
        p=Give_records(root->lptr,p);
        p=SortTrainsHelper(root->right,p);
    }
    return p;
}
void SortTrains()
{
    Tree_Node* root;
    root = Record_Root;
    Z_Node* p;
    p=NULL;
    p=SortTrainsHelper(root,p);
    printf("\n\t\t**********\tSortTrains() result is as follows\t**************\n");
    DisplayZList(p);
    DeleteZList(p);
    printf("\n\n");
}
void RangeSearch()
{
    printf("Please enter the from-train-number: ");
    int from_number;
    scanf("%d",&from_number);
    int flag;
    flag=0;
    int to_number;
    printf("Please enter the to-train-number: ");
    while(flag==0)
    {
        scanf("%d",&to_number);
        if(to_number>from_number)
        {
            flag=1;
        }
        else
        {
            printf("Please enter to-number greater than from-number : ");
        }
    }
    Train* arr;
    arr=train_array;
    int i;
    printf("\n\t******************\tResults are as follows\t******************\n");
    for(i=0;i<train_size;i++)
    {
        if(arr[i].data.id>=from_number && arr[i].data.id<=to_number)
        {
            printf("%s train with id %d\n",arr[i].data.name,arr[i].data.id);
            flag=0;
        }
    }
    if(flag==1)
    {
        printf("No records Found\n");
    }
    printf("\n\n");
}