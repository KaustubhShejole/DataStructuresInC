#include"Insertion.h"
#include"reservation.h"
bogie_seat* AppendInFilledList(int start,int end,int i,int train_index,travel_class t)
{
	bogie_seat *nptr,*lptr;
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
	int status=0;
	lptr=nptr;
	DisplayLIST(nptr);
	if(nptr->start==-1 && nptr->end == -1)
	{
		Append(start,end,nptr);
	}
	else
	{
		if(nptr->start>(end+1))
		{
			printf("Adding At Start\n");
			bogie_seat* ptr;
			ptr = (bogie_seat*)malloc(sizeof(bogie_seat));
			ptr->start = start;
			ptr->end = end;
			ptr->next = nptr;
			lptr = ptr;
			status=1;
		}
		while(nptr!=NULL && status==0)
		{
			if( nptr->end == start-1 )
			{
				nptr->end = end;
				if(nptr->next != NULL)
				{
					if(nptr->next->start == end+1)
					{
						bogie_seat* tptr;
						tptr = nptr->next;
						nptr->end = tptr->end;
						nptr->next = tptr->next;
						free(tptr);
						tptr=NULL;
					}
				}
				status=1;
			}
			else if(nptr->start == end+1)
			{
				nptr->start = start;
				if(nptr->next->start == nptr->end + 1)
				{
					bogie_seat* tptr;
					tptr = nptr->next;
					nptr->end = tptr->end;
					nptr->next = tptr->next;
					free(tptr);
					tptr = NULL;
				}
				status=1;
			}
			else
			{
				if(nptr->next != NULL)
				{
					if(nptr->next->start>end+1)
					{
						//Insert in between nptr and nptr->next
						status=1;
						bogie_seat* ptr;
						ptr = (bogie_seat*)malloc(sizeof(bogie_seat));
						ptr->start = start;
						ptr->end = end;
						ptr->next = nptr->next;
						nptr->next = ptr;
					}
				}
				else
				{
					//nptr->next = NULL
					//nptr cannot merge also only way is to insert at end
					status=1;
					bogie_seat* ptr;
					ptr = (bogie_seat*)malloc(sizeof(bogie_seat));
					ptr->start = start;
					ptr->end = end;
					ptr->next = nptr->next;
					nptr->next = ptr;
				}
			}
			nptr = nptr->next;
		}
	}
	return lptr;
}