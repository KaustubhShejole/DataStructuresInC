#include"InsertNode.h"
#include"reservation.h"
bogie_seat* RemovefromFilledList(int value,int train_index,int i,travel_class t)
{
    bogie_seat *nptr,*lptr;
    bogie_seat* next_ptr;
	if(t==0)
	{
		nptr = train_array[train_index].S_bogies[i].s.filled_seat_list;
	}
	else if(t==1)
		nptr = train_array[train_index].AC3_bogies[i].ac3.filled_seat_list;
	else if (t==2)
		nptr=train_array[train_index].AC2_bogies[i].ac2.filled_seat_list;
	else if(t==3)
		nptr = train_array[train_index].AC1_bogies[i].ac1.filled_seat_list;
    next_ptr=nptr->next;
	lptr=nptr;
    if(lptr->start==value && lptr->end==value)
    {
        lptr=lptr->next;
        free(nptr);
    }
    else if(value==lptr->start)
    {
        lptr->start = value+1;
    }
    
    else
    {
        while(next_ptr!=NULL)
        {
            if(next_ptr->start==value && next_ptr->end==value)
            {
                nptr->next = next_ptr->next;
                free(next_ptr);
            }
            else if(value==nptr->start)
            {
                next_ptr->start = value+1;
            }
            else if(value>nptr->start && value<nptr->end)
            {
                bogie_seat* temp_ptr;
                temp_ptr=(bogie_seat*)malloc(sizeof(bogie_seat));
                Append(value+1,nptr->end,temp_ptr);
                Append(nptr->start,value-1,temp_ptr);
                temp_ptr->next = nptr->next;
                nptr->next = temp_ptr;
            }
            next_ptr=nptr->next;
        }
    }
    return lptr;
}