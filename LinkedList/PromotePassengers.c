#include"InsertNode.h"
#include"reservation.h"

/*- PromotePassengers 
    • Input – Train id and date of travel
    • Output – For all the passengers on the train with train id and a particular date, 
    passengers can be promoted to next travel class (Sleeper -> 3AC -> 2AC ->1AC) if 
    seats are available. Passengers who had given consent for promotion to next class are 
    considered in the order of their date of booking. Note that if 2AC passenger is 
    promoted to 1AC, his/her 2AC seat becomes vacant and can be occupied by another 
    passenger from lower class under promotion.*/
extern Node* Record_List;

Node* PromotePassengers()
{
    Node* nptr;
    nptr=Record_List;
    DisplayTrainNames();
    int train_id;
    int status = 0;
    int i;
    int t_id;
    while(status==0)
    {
        int j;
        printf("Please enter train number or train id for promotion of passengers : ");
        scanf("%d",&j);
        
        for(i=0;i<train_size && status == 0;i++)
        {
            if(train_array[i].data.id == j)
            {
                status = 1;
                t_id = i;
            }
        }
        if(status==1)
        {
            train_id = j;
            status = 1;
        }
        else
        {
            printf("Please enter correct train_id ");
        }
    }
    date DATE;
	DATE = scan_date();
    Node* ptr;
    ptr=nptr;
    for(i=2;i>=0;i--)
    {
        nptr=Record_List;
        ptr=nptr;
        while(nptr!=NULL)
        {
            if(nptr->data.upgrade==1&&nptr->data.tclass==i)
            {
                if(nptr->data.train_id == train_id && is_equal_date(nptr->data.d,DATE))
                {
                    int num1;
                    num1=CheckFreeSeats(1,i+1);
                    if(num1>=1)
                    {
                        RemovefromFilledList(nptr->data.seat_number,t_id,nptr->data.bogie_number,i);
                        AddToFreeList(nptr->data.seat_number,ptr->data.seat_number,t_id,nptr->data.bogie_number,i);
                        if(ptr==Record_List)
                        {
                            Record_List = Record_List->next;
                        }
                        else
                        {
                            ptr->next = nptr->next;
                        }
                        DoReservation(nptr,1,t_id,i+1);
                    }
                }
            }
            nptr=nptr->next;
        }
    }
    return Record_List;
}