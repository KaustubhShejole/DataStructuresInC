#include"Insertion.h"
#include"reservation.h"
extern Tree_Node* Record_Root;
void DoReservation(Node* sub_lptr,int num,int train_index,travel_class t)
{
	bogie_seat** npptr;
	int i;
	int x;
	x = train_array[train_index].bogies[t];
	for(i=0;i<x;i++)
	{
		if(t==Sleeper)
		{
			npptr = &train_array[train_index].S_bogies[i].s.free_seat_list;
		}
		else if(t==AC3)
		{
			npptr = &train_array[train_index].AC3_bogies[i].ac3.free_seat_list;
		}
		else if(t==AC2)
		{
			npptr = &train_array[train_index].AC2_bogies[i].ac2.free_seat_list;
		}
		else if(t==AC1)
		{
			npptr = &train_array[train_index].AC1_bogies[i].ac1.free_seat_list;
		}
		bogie_seat* nptr;
		nptr = *npptr;
		bogie_seat* tptr;
		tptr = nptr;
		bogie_seat* ptr;
		ptr = tptr;
		while(sub_lptr !=NULL&&tptr!=NULL)
		{
			int temp;
			temp = tptr->start;
			while(sub_lptr!=NULL && temp<=tptr->end)
			{
				sub_lptr->data.seat_number = temp;
				sub_lptr->data.bogie_number = i;//here changed i+1
				sub_lptr = sub_lptr->next;
				temp++;
			}
			if(!((sub_lptr==NULL)&&((temp-1)!=tptr->end)))
			{
				AppendInFilledList(tptr->start,tptr->end,i,train_index,t);
				bogie_seat* temp_ptr;
				temp_ptr = tptr;
				if(tptr==nptr)
				{
					nptr = nptr->next;
				}
				else
				{
					ptr->next = tptr->next;
				}
				//num = num + tptr->end - tptr->start + 1;
				ptr = tptr;
				tptr = tptr->next;
				free(temp_ptr);
			}
			else if(sub_lptr==NULL && (temp-1) < tptr->end)
			{
				AppendInFilledList(tptr->start,temp-1,i,train_index,t);
				tptr->start = temp;
			}
		}
		*npptr = nptr;
	}
}
int CheckFreeSeats(int train_index,travel_class t)
{
	bogie_seat* nptr;
	int num;
	num = 0;
	int i;
	int x;
	x = train_array[train_index].bogies[t];
	for(i=0;i<x;i++)
	{
		if(t==Sleeper)
		{
			nptr = train_array[train_index].S_bogies[i].s.free_seat_list;
		}
		else if(t==AC3)
		{
			nptr = train_array[train_index].AC3_bogies[i].ac3.free_seat_list;

		}
		else if(t==AC2)
		{
			nptr = train_array[train_index].AC2_bogies[i].ac2.free_seat_list;
		}
		else if(t==AC1)
		{
			nptr = train_array[train_index].AC1_bogies[i].ac1.free_seat_list;
		}
		bogie_seat* tptr;
		tptr = nptr;
		while(tptr!=NULL)
		{
			num = num + tptr->end - tptr->start + 1;
			tptr = tptr->next;
		}
	}
	return num;
}
int partial_reservation_helper(Node* sub_lptr,int num1,int train_index,int status,travel_class t)
{
	Node* ptr;
	ptr = sub_lptr;
	Node* temp_ptr;
	temp_ptr=ptr;
	printf("Number of seats not sufficient would you like to have partial reservation\n");
	printf("Please enter 1 if you want to have partial reservation else enter 0: ");
	int flag;
	scanf("%d",&flag);
	if(flag == 1)
	{
		
			printf("Please enter number of passengers you want now less than or equal to %d: ",num1);
			int requirement;
			scanf("%d",&requirement);
			int bound;
			bound=0;
			while(bound==0)
			{
				if(requirement>0 && requirement<=num1)
				{
					bound=1;
				}
				else
				{
					printf("Please enter num between 1 and %d both inclusive: ",num1);
					scanf("%d",&requirement);
				}
			}
			int index;
		for(index=0;index<requirement &&status==0;index=index+1)
		{
			printf("Please enter your passenger id if you have else put -1:");
			int temp;
			scanf("%d",&temp);
			fflush(stdin);
			char s[90];
			char pname[90];
			int flag;
			flag = 0;
			while(temp!=-1 && flag == 0)
			{
				while((give_pname(temp,s)==0) && (temp!=-1))
				{
					printf("Not Valid id please give other or enter -1:");
					scanf("%d",&temp);
					fflush(stdin);
				}
				if(temp!=-1)
				{
					printf("%s\n",s);
					int j;
					printf("If it is your name enter 1 else 0: ");
					scanf("%d",&j);
					if(j==1)
					{
						strcpy(pname,s);
						flag = 1;
					}
					else
					{
						printf("Please enter your passenger id if you have else put -1:");
						scanf("%d",&temp);
					}
				}
			}
			if(temp==-1)
			{
				fflush(stdin);
				printf("\nPlease Enter the Passenger Name:");
				scanf("%[^\n]s",pname);
			}
			strcpy((ptr->data).pname,pname);
			if((ptr->data).tclass != AC1)
			{
				int p;
				printf("Please enter 1 if you like to have upgrade else enter 0: ");
				scanf("%d",&p);
				if(p>0)
				{
					(ptr->data).upgrade = TRUE;
				}
				else
				{
					(ptr->data).upgrade = FALSE;
				}
			}
			else
			{
				(ptr->data).upgrade=0;
			}
			if(index+1 == requirement)
			{
				temp_ptr = ptr->next;
				DeleteList(temp_ptr);
				ptr->next = NULL;
				printf("here i am\n");
				DoReservation(sub_lptr,requirement,train_index,ptr->data.tclass);
				printf("partial reservation done");
				status = 2;
				//exit(1);
			}
			else
			{
				ptr = ptr->next;
			}
			//sub_lptr = InsertAtList(nptr,sub_lptr);
		}
	}
	if(status==2)
	{
		Record_Root = Insert_List_In_Tree(Record_Root,sub_lptr);
		DisplayTree(Record_Root);
		printf("Partial Reservation Done successfully.\n");
	}
	return status;
}
