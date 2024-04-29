#include"Insertion.h"
//#include"reservation.h"
extern int id;

Boolean found_station(int key,int train_id,int start)
{
	Boolean status;
	status = FALSE;
	
	int i;
	i = 0;
	int flag;
	flag = 0;
	if(start > 0)
	{
		while(i<train_array[train_id].station_size && flag == 0)
		{
			if(train_array[train_id].starr[i].data.id == start)
			{
				flag = 1;
			}
			i++;
		}
	}
	else
	{
		flag=1;
	}
	while(i<train_array[train_id].station_size && flag == 1)
	{
		if(train_array[train_id].starr[i].data.id == key)
		{
			flag = 0;
			status = TRUE;
		}
		i++;
	}
		
	return status;
}
Boolean is_last(int i,int train_id)
{
	Boolean ret_val = FALSE;
	if(train_array[train_id].starr[train_array[train_id].station_size-1].data.id == i)
	{
		ret_val = TRUE;
	}
	return ret_val;
}
int scan_station_id(int train_id,int start,int bbb)
{
	int status,j;
	status = 0;
	int i;
	for(i=0;status==0&&i<train_size;i++)
	{
		if(train_id == train_array[i].data.id)
		{
			status=1;
			train_id = i;
		}
	}
	
	if(status == 1)
    	{
			while(status==1)
			{
				scanf("%d",&j);
				//status=0;
				if(bbb == 1)
				{
					
					while(is_last(j,train_id))
					{
						printf("Boarding Station is Last One it is not possible\n");
						printf("Please enter another ");
						scanf("%d",&j);
					}
				}
				if(found_station(j,train_id,start))
				{
					status = 0;
				}
				else if(found_station(j,train_id,0))
				{
					printf("The Destination Station is behind Boarding Station so please enter correct station_id ");
				}
				else
				{
					printf("Please enter correct station_id ");
				}
			}
    	}
    return j;
}
void DisplayTrainNames()
{
	int i;
	i=0;
	while(i<train_size)
	{
		printf("%d %s\n",train_array[i].data.id,train_array[i].data.name);
		i++;
	}
}
int train_found(int key)
{
	int i;
	Boolean ret_val;
	ret_val = 0;
	for(i=0;i<train_size && ret_val == 0;i++)
	{
		if(train_array[i].data.id == key)
		{
			ret_val = 1;
		}
	}
	return ret_val;
}
void print_date(date d)
{
	printf("Date = %d-%d-%d\n",d.dd,d.mm,d.yy);
}
void DisplayRecord(Itemtype* r)
{
    printf("Passenger name : ");
    printf("%s\n",(r->pname));
    printf("Passenger id : %d\n",(r->pid));
    printf("Train id : %d\n",r->train_id);
    printf("Train name : %s\n",r->tname);
    
    printf("Boarding station number : %d\n",r->bstat_num);
    printf("Boarding station name : %s\n",r->bstation);
    
    printf("Destination Station Number : %d\n",r->dstat_num);
    printf("Destination Station Name : %s\n",r->dstation);
    print_date(r->d);
	print_tclass(r->tclass);
	printf("Upgrade = %d\n",r->upgrade);
	printf("Bogie Number : %d\n",r->bogie_number+1);
	printf("Seat Number : %d\n",r->seat_number);
}