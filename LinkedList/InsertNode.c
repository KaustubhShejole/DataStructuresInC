#include"InsertNode.h"
extern int id;
extern Node* Record_List;
Boolean valid_date(date d)
{
	Boolean ret_val;
	ret_val = FALSE;
	if (d.mm<=12 && d.mm>0)
	{
		if(d.dd<=31 && d.dd>0)
		{
			switch(d.mm)
			{
				case 4:
				case 6:
				case 9:
				case 11:
					if(d.dd<=30)
					{
						ret_val = TRUE;
					}
				break;
				case 2:
					if(d.yy%4 == 0)
					{
						if(d.dd<=29)
						{
							ret_val = TRUE;
						}
					}
					else
					{
						if(d.dd<=28)
						{
							ret_val = TRUE;
						}
					}
				break;
				default:
					ret_val = TRUE;
			}
		}
	}
	return ret_val;
}
date scan_date()
{
	date d;
	do
	{
		printf("Please enter date in dd mm yyyy format: ");
		scanf("%d %d %d",&d.dd,&d.mm,&d.yy);
	}while(!valid_date(d));
	return d;
}
void InsertList()
{
	int group;
	printf("Group implies one boarding,train,travel class,destination :");
	printf(" Please number of passengers in a group : "); 
	scanf("%d",&group);
	if(group>0)
	{
		int train_id;
		int bb,dd;
		char b[90],d[90];
		char pname[90];
		travel_class tclass;
		DisplayTrainNames();
		int status = 0;
		int i;
		int t_id;
		while(status==0)
		{
			int j;
			printf("Please enter train number or train id : ");
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
		//printf("Please enter 0 for Sleeper\n1 for AC1\n2 for AC2\n3 for AC3: ");
		
		int flag;
		flag = 0;
		do
		{
			if(train_array[t_id].bogies[0]!=0)
			{
				printf("enter 0 for Sleeper\n");
			}
			if(train_array[t_id].bogies[3]!=0)
			{
				printf("enter 1 for AC1\n");
			}
			if(train_array[t_id].bogies[2]!=0)
			{
				printf("enter 2 for AC2\n");
			}
			if(train_array[t_id].bogies[1]!=0)
			{
				printf("enter 3 for AC3\n");
			}
			int dp;
			scanf("%d",&(dp));
			switch(dp)
			{
				case 0:
				if(train_array[t_id].bogies[0]!=0)
				{
					tclass = Sleeper;
					flag=1;
				}
				break;
				case 1:
				if(train_array[t_id].bogies[3]!=0)
				{
					tclass = AC1;
					flag = 1;
				}
				break;
				case 2:
				if(train_array[t_id].bogies[2]!=0)
				{
					tclass = AC2;
					flag=1;
				}
				break;
				case 3:
				if(train_array[t_id].bogies[1]!=0)
				{
					tclass = AC3;
					flag=1;
				}
				break;
			}
		}while(flag==0);

		ShowStations(train_id);
		printf("Please enter the boarding station number or id : ");
		bb = scan_station_id(train_id,0,1);
		strcpy(b,station_array[bb-1].data.name);
		printf("Please enter the destination station number or id : ");
		//str = give_station(r->bstat_num);
		dd = scan_station_id(train_id,bb,0);
		strcpy(d,station_array[dd-1].data.name);
		date DATE;
		DATE = scan_date();
		int num;
		num = group;
		int pid;
		Node* sub_lptr;
		sub_lptr = NULL;
		for(;group!=0;group--)
		{
			Node* nptr;
			nptr = NULL;
			nptr = (Node*)malloc(sizeof(Node));
			(nptr->data).bstat_num = bb;//boarding station id
			(nptr->data).dstat_num = dd;//destination station id
			(nptr->data).tclass = tclass;//travelling class
			(nptr->data).train_id = train_id;//train number
			strcpy((nptr->data).tname,train_array[i-1].data.name);//train name
			strcpy((nptr->data).bstation,b);
			strcpy((nptr->data).dstation,d);
			(nptr->data).d = DATE;
			printf("Please enter your passenger id if you have else put -1:");
			int temp;
			scanf("%d",&temp);
			fflush(stdin);
			char s[90];
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
						pid = temp;
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
				pid = id;
				id = id + 1;
				fflush(stdin);
				printf("\nPlease Enter the Passenger Name:");
				scanf("%[^\n]s",pname);
			}
			nptr->data.pid = pid;
			strcpy((nptr->data).pname,pname);
			if((nptr->data).tclass != AC1)
			{
				int p;
				printf("Please enter 1 if you like to have upgrade else enter 0: ");
				scanf("%d",&p);
				if(p>0)
				{
					(nptr->data).upgrade = TRUE;
				}
				else
				{
					(nptr->data).upgrade = FALSE;
				}
			}
			else
			{
				(nptr->data).upgrade=0;
			}
			sub_lptr = InsertAtList(nptr,sub_lptr);
		}
		int success;
		success = 0;
		success = reservation(sub_lptr,num,t_id);
		if(success==1)
		{
			AddSub_list(sub_lptr);
			DisplayList(Record_List);
		}
	}
	else
	{
		printf("Number of passengers not valid\n");
	}
}

void DisplayInRecordFile(Itemtype* r,FILE* fp)
{
	fprintf(fp,"%d ",(r->pid));
    fprintf(fp,"%s\n",(r->pname));
    fprintf(fp,"%d ",r->train_id);
    fprintf(fp,"%s\n",r->tname);
    
    fprintf(fp,"%d ",r->bstat_num);
    fprintf(fp,"%s\n",r->bstation);
    
    fprintf(fp,"%d ",r->dstat_num);
    fprintf(fp,"%s\n",r->dstation);
	fprintf(fp,"%d %d %d\n",r->tclass,r->bogie_number,r->seat_number);
	fprintf(fp,"%d %d %d\n",r->d.dd,r->d.mm,r->d.yy);
}
void DisplayList(Node* lptr)
{
	while(lptr!=NULL)
	{
		DisplayRecord(&(lptr->data));
		printf("\n");
		lptr = lptr->next;
	}
}

void Insert()
{
	int status;
	printf("To insert a passenger enter 1 else 0 : ");
	scanf("%d",&status);
	if(status==1)
	{
		InsertList();
	}
	printf("\n");
}
void StoreRecords()
{
	FILE* fp;
	fp = fopen("records.txt","r");
	char str[90];
	int i;
	i=0;
	int d;
	char s[90];
	Node* nptr;
	int status=0;
	nptr = (Node*)malloc(sizeof(Node));
	while(fgets(str,90,fp))
	{
		status=1;
		switch(i)
		{
			case 0:
			case 1:
			case 2:
			case 3:
				sscanf(str,"%d %[^\n]s",&d,s);
				switch(i)
				{
					case 0: nptr->data.pid = d;
					strcpy(nptr->data.pname,s);
					break;
					case 2:nptr->data.bstat_num=d;
					strcpy(nptr->data.bstation,s);
					break;
					case 3:nptr->data.dstat_num = d;
					strcpy(nptr->data.dstation,s);
					break;
					case 1:
					nptr->data.train_id = d;
					strcpy(nptr->data.tname,s);
				}
			break;
			case 4:
				sscanf(str,"%d %d %d",&(nptr->data.tclass),&(nptr->data.bogie_number),&(nptr->data.seat_number));
				
			break;
			case 5:
				sscanf(str,"%d %d %d",&(nptr->data.d.dd),&(nptr->data.d.mm),&(nptr->data.d.yy));
			break;
		}
		if(i==5)
		{
			i=0;
			AddSub_list(nptr);
			//DisplayRecord(&nptr->data);
			nptr = (Node*)malloc(sizeof(Node));
			id++;
			status=0;
		}
		else
		{
			i=i+1;
		}
	}
	if(status==0)
	{
		free(nptr);
	}
	fclose(fp);
	DisplayList(Record_List);
}
Node* DeleteNode()
{
    printf("Please enter the passenger id whose all records needs to be deleted :");
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
        Node* nptr;
        Node* ptr;
        nptr=Record_List;
        ptr=nptr;
        if(nptr->data.pid==temp)
        {
            Record_List = Record_List->next;
            free(nptr);
        }
        while(nptr->next!=NULL)
        {
            if (nptr->next->data.pid == temp)
            {
                ptr=nptr->next;
                nptr->next = nptr->next->next;
                free(ptr);
            }
            if(nptr->next!=NULL)
            {
                nptr=nptr->next;
            }
        }
		printf("\n\tDeletion of nodes of passenger with %d id Successfully Done\n\n",temp);
    }
	else
	{
		printf("\n\tDeletion Failed\n");
	}
    return Record_List;
}

/*int main()
{
	StoreStations();
	StoreTrains();
	DisplayTrains();
	DisplayStations();
	Node* lptr;
	lptr = NULL;
	lptr = Insert(lptr);
	DisplayList(lptr);
	DeleteList(lptr);
	Delete(train_array);
	free(station_array);
	
    return 0;
}*/
