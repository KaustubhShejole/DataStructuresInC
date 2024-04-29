#include"Insertion.h"
#include"reservation.h"

int reservation(Node* sub_lptr,int num,int id)
{
	int ret_val;
	ret_val = 0;
	printf("For Reservation \n");
	travel_class tclass;
	tclass = sub_lptr->data.tclass;
	int i;
	i = tclass;
	int x = train_array[id].bogies[i];
	if(x<=0)
	{
		printf("reservation not possible 'Impossible Case'\n");
	}
	else
	{
		if(tclass == AC1)
		{
			if(train_array[id].AC1_bogies[0].ac1.filled_seat_list == NULL)
			{
				train_array[id].AC1_bogies = (AC1_bogie*)malloc(sizeof(AC1_bogie)*x);
				int num_bogies;
				for(num_bogies=0;num_bogies<x;num_bogies++)
				{
					train_array[id].AC1_bogies[num_bogies].ac1.filled_seat_list = (bogie_seat*)malloc(sizeof(bogie_seat));
					train_array[id].AC1_bogies[num_bogies].ac1.free_seat_list = (bogie_seat*)malloc(sizeof(bogie_seat));
					Append(-1,-1,train_array[id].AC1_bogies[num_bogies].ac1.filled_seat_list);
					Append(1,AC1_size,train_array[id].AC1_bogies[num_bogies].ac1.free_seat_list);
				}
				//Give_Seat_Numbers(sub_lptr,1,num,0);
				//Append(1,num,train_array[id].AC1_bogies[0].ac1.filled_seat_list);
				//Append(num+1,AC1_size,train_array[id].AC1_bogies[0].ac1.free_seat_list);
				ret_val = CheckAC1(sub_lptr,num,id);
				DisplayLIST(train_array[id].AC1_bogies[0].ac1.filled_seat_list);
				DisplayLIST(train_array[id].AC1_bogies[0].ac1.free_seat_list);
				printf("Reservation Done Successfully\n");
			}
			else
			{
				ret_val = CheckAC1(sub_lptr,num,id);
			}
		}
		else if(tclass == AC2)
		{
			if(train_array[id].AC2_bogies[0].ac2.filled_seat_list == NULL)
			{
				train_array[id].AC2_bogies = (AC2_bogie*)malloc(sizeof(AC2_bogie)*x);
				int num_bogies;
				for(num_bogies=0;num_bogies<x;num_bogies++)
				{
					train_array[id].AC2_bogies[num_bogies].ac2.filled_seat_list = (bogie_seat*)malloc(sizeof(bogie_seat));
					train_array[id].AC2_bogies[num_bogies].ac2.free_seat_list = (bogie_seat*)malloc(sizeof(bogie_seat));
					Append(-1,-1,train_array[id].AC2_bogies[num_bogies].ac2.filled_seat_list);
					Append(1,AC2_size,train_array[id].AC2_bogies[num_bogies].ac2.free_seat_list);
				}
				//Give_Seat_Numbers(sub_lptr,1,num,0);
				ret_val =CheckAC2(sub_lptr,num,id);
				//Append(1,num,train_array[id].AC2_bogies[0].ac2.filled_seat_list);
				//Append(num+1,AC2_size,train_array[id].AC2_bogies[0].ac2.free_seat_list);
				DisplayLIST(train_array[id].AC2_bogies[0].ac2.filled_seat_list);
				DisplayLIST(train_array[id].AC2_bogies[0].ac2.free_seat_list);
				printf("Reservation Done Successfully\n");
			}
			else
			{
				ret_val =CheckAC2(sub_lptr,num,id);
			}
		}
		else if(tclass == AC3)
		{
			if(train_array[id].AC3_bogies[0].ac3.filled_seat_list == NULL)
			{
				train_array[id].AC3_bogies = (AC3_bogie*)malloc(sizeof(AC3_bogie)*x);
				int num_bogies;
				for(num_bogies=0;num_bogies<x;num_bogies++)
				{
					train_array[id].AC3_bogies[num_bogies].ac3.filled_seat_list = (bogie_seat*)malloc(sizeof(bogie_seat));
					train_array[id].AC3_bogies[num_bogies].ac3.free_seat_list = (bogie_seat*)malloc(sizeof(bogie_seat));
					Append(-1,-1,train_array[id].AC3_bogies[num_bogies].ac3.filled_seat_list);
					Append(1,AC2_size,train_array[id].AC3_bogies[num_bogies].ac3.free_seat_list);
				}
				DisplayLIST(train_array[id].AC3_bogies[0].ac3.filled_seat_list);
				DisplayLIST(train_array[id].AC3_bogies[0].ac3.free_seat_list);
				ret_val =CheckAC3(sub_lptr,num,id);
				printf("Reservation Done Successfully\n");
			}
			else
			{
				ret_val =CheckAC3(sub_lptr,num,id);
			}
		}
		else if(tclass == Sleeper)
		{
			if(train_array[id].S_bogies[0].s.filled_seat_list == NULL)
			{
				printf("Here is NULL\n");
				//train_array[id].S_bogies = (S_bogie*)malloc(sizeof(S_bogie)*x);
				int num_bogies;
				for(num_bogies=0;num_bogies<x;num_bogies++)
				{
					train_array[id].S_bogies[num_bogies].s.filled_seat_list = (bogie_seat*)malloc(sizeof(bogie_seat));
					train_array[id].S_bogies[num_bogies].s.free_seat_list = (bogie_seat*)malloc(sizeof(bogie_seat));
					Append(-1,-1,train_array[id].S_bogies[num_bogies].s.filled_seat_list);
					Append(1,S_size,train_array[id].S_bogies[num_bogies].s.free_seat_list);
				}
				ret_val=CheckS(sub_lptr,num,id);
				/*Give_Seat_Numbers(sub_lptr,1,num,0);
				Append(1,num,train_array[id].S_bogies[0].s.filled_seat_list);
				Append(num+1,S_size,train_array[id].S_bogies[0].s.free_seat_list);*/
				DisplayLIST(train_array[id].S_bogies[0].s.filled_seat_list);
				DisplayLIST(train_array[id].S_bogies[0].s.free_seat_list);
				printf("Reservation Done Successfully\n");
			}
			else
			{
				ret_val=CheckS(sub_lptr,num,id);
			}
		}

	}
	return ret_val;
}
