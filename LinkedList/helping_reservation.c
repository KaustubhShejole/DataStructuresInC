#include"InsertNode.h"
#include"reservation.h"
extern Node* Record_List;
void Give_Seat_Numbers(Node* sub_lptr,int start,int end,int index)
{
	Node* nptr;
	nptr=sub_lptr;
	while(nptr!=NULL && end>=start)
	{
		nptr->data.bogie_number = index;
		nptr->data.seat_number = start;
		nptr=nptr->next;
		start++;
	}
	DisplayList(sub_lptr);
}
void DisplayLIST(bogie_seat* b)
{
	bogie_seat* ptr;
	ptr = b;
	printf("[ ");
	while(ptr!=NULL)
	{
		printf("[ %d %d] ",ptr->start,ptr->end);
		ptr=ptr->next;
	}
	printf(" ]\n");
}
void Append(int start,int end,bogie_seat* bogie_list)
{
    bogie_list->start = start;
    bogie_list->end = end;
    bogie_list->next = NULL;
}
int CheckAC1(Node* sub_lptr,int num,int train_index)
{
    printf("AC1check\n");
	int status=0;
	if(status==0)
	{
		int num1;
		num1 = CheckFreeSeats(train_index,AC1);
		if(num1>=num)
		{
			DoReservation(sub_lptr,num,train_index,AC1);
			status = 1;
		}
		else if(num1<num && num1!=0)
		{
			status = partial_reservation_helper(sub_lptr,num1,train_index,status,AC1);
		}
	}
	if(status==0)
	{
		printf("Reservation Not Done Successfully!!!\n\n");
		sub_lptr = DeleteList(sub_lptr);
	}
	else{
		printf("Reservation Done Successfully: \n");
	}
    return status;
}
int CheckAC2(Node* sub_lptr,int num,int train_index)
{
    printf("AC2Check\n");
	int status=0;
	if(status==0)
	{
		int num1;
		num1 = CheckFreeSeats(train_index,AC2);
		if(num1>=num)
		{
			DoReservation(sub_lptr,num,train_index,AC2);
			status = 1;
		}
		else if(num1<num && num1!=0)
		{
			status = partial_reservation_helper(sub_lptr,num1,train_index,status,AC2);
		}
	}
	if(status==0)
	{
		printf("Reservation Not Done Successfully!!!\n\n");
		sub_lptr = DeleteList(sub_lptr);
	}
	else{
		printf("Reservation Done Successfully: \n");
	}
    return status;
}
int CheckAC3(Node* sub_lptr,int num,int train_index)
{
    printf("AC3Check\n");
	int status=0;
	if(status==0)
	{
		int num1;
		num1 = CheckFreeSeats(train_index,AC3);
		printf("%d = num1\n",num1);
		if(num1>=num)
		{
			DoReservation(sub_lptr,num,train_index,AC3);
			status = 1;
		}
		else if(num1<num && num1!=0)
		{
			status = partial_reservation_helper(sub_lptr,num1,train_index,status,AC3);
		}
	}
	if(status==0)
	{
		printf("Reservation Not Done Successfully!!!\n\n");
		sub_lptr = DeleteList(sub_lptr);
	}
	else{
		printf("Reservation Done Successfully: \n");
	}
    return status;
}
int CheckS(Node* sub_lptr,int num,int train_index)
{
    printf("SCheck\n");
	int status=0;
	if(status==0)
	{
		int num1;
		num1 = CheckFreeSeats(train_index,Sleeper);
		if(num1>=num)
		{
			DoReservation(sub_lptr,num,train_index,Sleeper);
			status = 1;
		}
		else if(num1<num && num1!=0)
		{
			status = partial_reservation_helper(sub_lptr,num1,train_index,status,Sleeper);
		}
	}
	if(status==0)
	{
		printf("Reservation Not Done Successfully!!!\n\n");
		sub_lptr = DeleteList(sub_lptr);
	}
	else{
		printf("Reservation Done Successfully: ");
	}
    return status;
}
