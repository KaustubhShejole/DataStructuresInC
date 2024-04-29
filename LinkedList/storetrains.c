#include "storetrains.h"
#include<string.h>
#include<stdlib.h>
#include"storestations.h"
extern Station* station_array;
int to_num(char* str)
{
	int num;
	num =0;
	int i;
	i=0;
	while(i<strlen(str))
	{
		int j;
		j = str[i]-'0';
		num = num*10 + j;
		i++;
	}
	return num;
}
void StoreTrains()
{
	//char arr[
	char str[90];
	FILE *fp = fopen("train_details.txt","r");
	int i = 0;
	while(fgets(str,90,fp))
	{
		i++;
	}
	train_size = i;
	fclose(fp);
	train_array = (Train*)malloc((sizeof(Train))*i);
	char name[80];
	fp = fopen("train_details.txt","r");
	i=0;
	int id;
	while(fgets(str,90,fp))
	{
		sscanf(str,"%d %[^\n]s ",&id,name);
		train_array[i].data.id = id;
		strcpy(train_array[i].data.name,name);
		i++;
	}
	fclose(fp);
	fp = fopen("train_route_details.txt","r");
	i=0;
	if(fp==NULL)
	{
		printf("Error\n");
	}
	else
	{
		while(fgets(str,90,fp))
		{
			int k;
			int j;
			j = 0;
			k = 0;
			//printf("\n");
			
			while(k<strlen(str))
			{
				int p;
				p = 0;
				//char num[3];
				while(str[k] != ' ' && str[k] !='\0' && str[k]!='\n')
				{
				
						//num[p] = str[k];
						//printf("num[%d] = %c\n",p,str[k]);
						k++;
						p++;
						
				}
				
				//printf("%s %ld ",num,strlen(num));
				//printf("%d ",n);
				//train_array[i].starr[j].data.id = n;
				//strcpy(train_array[i].starr[j].data.name,station_array[n-1].data.name);
				//printf("%s\n",station_array[n-1].data.name);
				if(str[k] == ' '||str[k] == '\0' || str[k] == '\n')
				{
					k++;
				}
				j++;
				
			}
			train_array[i].station_size = j;
			train_array[i].starr = (Station*)malloc((sizeof(Station))*j);
			j = 0;
			k = 0;
			while(k<strlen(str))
			{
				int p;
				p = 0;
				char num[3];
				while(str[k] != ' ' && str[k] !='\0' && str[k]!='\n')
				{
						num[p] = str[k];
						k++;
						p++;
				}
				int n;
				n = to_num(num);
				train_array[i].starr[j].data.id = n;
				strcpy(train_array[i].starr[j].data.name,station_array[n-1].data.name);
				//printf("%s\n",station_array[n-1].data.name);
				if(str[k] == ' '||str[k] == '\0' || str[k] == '\n')
				{
					k++;
				}
				j++;
				
			}
			i++;
		}
	}
	fclose(fp);
	fp = fopen("bogie_details.txt","r");
	i = 0;
	while(fgets(str,90,fp))
	{
		int a,b,c,d;
		sscanf(str,"%d %d %d %d",&a,&b,&c,&d);
		train_array[i].bogies[0] = a;
		train_array[i].bogies[1] = b;
		train_array[i].bogies[2] = c;
		train_array[i].bogies[3] = d;
		i = i+1;
	}
	int j;
	for(j=0;j<i;j++)
	{
		int k;
		for(k=0;k<4;k++)
		{
			if(train_array[j].bogies[k]!=0)
			{
				if(k==3)
					//train_array[j].AC1_bogies = NULL;
					train_array[j].AC1_bogies = (AC1_bogie*)malloc(sizeof(AC1_bogie)*train_array[j].bogies[k]);
					//train_array[j].AC1_bogies[i].ac1.filled_seat_list = NULL;
					//train_array[j].AC2_bogies[i].ac1.filled_seat_list = NULL;
				else if(k==2)
					//train_array[j].AC2_bogies = NULL;
					train_array[j].AC2_bogies = (AC2_bogie*)malloc(sizeof(AC2_bogie)*train_array[j].bogies[k]);
				else if(k==1)
					//train_array[j].AC3_bogies = NULL;
					train_array[j].AC3_bogies = (AC3_bogie*)malloc(sizeof(AC3_bogie)*train_array[j].bogies[k]);
				else
					//train_array[j].S_bogies = NULL;
					train_array[j].S_bogies = (S_bogie*)malloc(sizeof(S_bogie)*train_array[j].bogies[k]);
			}
		}
	}
	fclose(fp);
	
	j=0;
	for(j=0;j<train_size;j++)
	{
		int k;
		for(k=0;k<4;k++)
		{
			int x = train_array[j].bogies[k];
			int i;
			for(i=0;i<x;i++)
			{
				if(train_array[j].bogies[k]!=0)
				{
					if(k==3)
					{	//train_array[j].AC1_bogies = (AC1_bogie*)malloc(sizeof(AC1_bogie)*train_array[j].bogies[k]);
						train_array[j].AC1_bogies[i].ac1.filled_seat_list = NULL;
						train_array[j].AC1_bogies[i].ac1.filled_seat_list = NULL;
					}
					else if(k==2)
					{	//train_array[j].AC2_bogies = (AC2_bogie*)malloc(sizeof(AC2_bogie)*train_array[j].bogies[k]);
						train_array[j].AC2_bogies[i].ac2.filled_seat_list = NULL;
						train_array[j].AC2_bogies[i].ac2.filled_seat_list = NULL;
					}
					else if(k==1)
					{	//train_array[j].AC3_bogies = (AC3_bogie*)malloc(sizeof(AC3_bogie)*train_array[j].bogies[k]);
						train_array[j].AC3_bogies[i].ac3.filled_seat_list = NULL;
						train_array[j].AC3_bogies[i].ac3.filled_seat_list = NULL;
					}
					else
					{	//train_array[j].S_bogies = (S_bogie*)malloc(sizeof(S_bogie)*train_array[j].bogies[k]);
						train_array[j].S_bogies[i].s.filled_seat_list = NULL;
						train_array[j].S_bogies[i].s.filled_seat_list = NULL;
					}
				}
			}
		}
	}
	
}			

void ShowTrain(Train x)
{
	printf("\n%d %s\n",x.data.id,x.data.name);
	//printf("Stations :");
	//ShowStations(x.data.id);
	printf("\n");
}
void DisplayBogies()
{
	int i;
	for(i=0;i<train_size;i++)
	{
		printf("%d Sleeper Bogies,%d AC3 Bogies",train_array[i].bogies[0],train_array[i].bogies[1]);
		printf(",%d AC2 Bogies,%d AC1 Bogies\n",train_array[i].bogies[2],train_array[i].bogies[3]);
	}
}
void DisplayTrains()
{
	int i = 0;
	while(i<train_size)
	{
		ShowTrain(train_array[i]);
		printf("%d Sleeper Bogies,%d AC3 Bogies",train_array[i].bogies[0],train_array[i].bogies[1]);
		printf(",%d AC2 Bogies,%d AC1 Bogies\n",train_array[i].bogies[2],train_array[i].bogies[3]);
		ShowStations(train_array[i].data.id);
		i++;
	}
}
void Delete(Train* t)
{
	t = train_array;
	int i;
	for(i=0;i<train_size;i++)
	{
		free(t[i].starr);
	}
	int j;
	for(j=0;j<train_size;j++)
	{
		for(i=0;i<4;i++)
		{
			int k;
			k=0;
			for(k=0;k<train_array[j].bogies[i];k++)
			{
				if(train_array[j].bogies[i]!=0)
				{
					switch(i)
					{
						case 0: //free AC1 blocks
							free(train_array[j].AC1_bogies[k].ac1.filled_seat_list);
							free(train_array[j].AC1_bogies[k].ac1.free_seat_list);
							free(train_array[j].AC1_bogies);
							break;
						case 1:
							free(train_array[j].AC2_bogies[k].ac2.filled_seat_list);
							free(train_array[j].AC2_bogies->ac2.free_seat_list);
							//free(train_array[j].AC2_bogies);
							break;
						case 2:
							free(train_array[j].AC3_bogies[k].ac3.filled_seat_list);
							free(train_array[j].AC3_bogies->ac3.free_seat_list);
							//free(train_array[j].AC3_bogies);
							break;
						case 3:
							free(train_array[j].S_bogies->s.filled_seat_list);
							free(train_array[j].S_bogies->s.free_seat_list);
							//free(train_array[j].S_bogies);
							break;
					}
				}

			}
		}
		free(train_array[j].AC1_bogies);
		free(train_array[j].AC2_bogies);
		free(train_array[j].AC3_bogies);
		free(train_array[j].S_bogies);

	}
	for(j=0;j<train_size;j++)
	{
		for(i=0;i<4;i++)
		{
			int k;
			for(k=0;k<train_array[j].bogies[i];k++)
			{
				if(train_array[j].bogies[i]!=0)
				{
					switch(i)
					{
						case 0:
							free(train_array[j].AC1_bogies);
							break;
						case 1:
							free(train_array[j].AC2_bogies);
							break;
						case 2:
							free(train_array[j].AC3_bogies);
							break;
						case 3:
							free(train_array[j].S_bogies);
							break;
					}
				}

			}
		}
	}
	free(t);
}
/*void fun()
{
	int i;
	int j;
	for(j=0;j<i;j++)
	{
		int k;
		for(k=0;k<4;k++)
		{
			int x = train_array[j].bogies[k];
			if(x!=0)
			{
				switch(k)
				{
					case 0:
					//train_array[j].S_bogies = (S_bogie*)malloc(sizeof(S_bogie)*x);
					//train_array[j].S_bogies->s=NULL;
					train_array[j].S_bogies = NULL;
					break;
					case 1:
					//train_array[i].AC3_bogies = (AC3_bogie*)malloc(sizeof(AC3_bogie)*x);
					//train_array[j].AC3_bogies->ac3=NULL;
					train_array[j].AC3_bogies = NULL;
					break;
					case 2:
					//train_array[i].AC2_bogies = (AC2_bogie*)malloc(sizeof(AC2_bogie)*x);
					//train_array[j].AC2_bogies->ac2=NULL;
					train_array[j].AC2_bogies = NULL;
					break;
					case 3:
					//train_array[j].AC1_bogies = (AC1_bogie*)malloc(sizeof(AC1_bogie)*x);
					//train_array[j].AC1_bogies->ac1=NULL;
					train_array[j].AC1_bogies = NULL;
					break;
				}
			}
		}
	}
}*/
/*int main()
{
	StoreStations();
	//DisplayStations();
	StoreTrains();
	DisplayTrains();
	//printf("%s",station_array[30].data.name);
	Delete(train_array);
	free(station_array);
	//free(train_array);
	FILE* fp = fopen("train_route_details.txt","r");
	char str[90];
	int i=0;
	if(fp!=NULL)
	{	while(fgets(str,90,fp))
		{
			int k;
			int j;
			j = 0;
			k = 0;
			int l;
			//printf("\n%ld\n",strlen(str));
			printf("\n");
			while(k<strlen(str))
			{
				int p;
				p = 0;
				char num[6];
				while(str[k] != ' ' && str[k] !='\0' && str[k]!='\n')
				{
						num[p] = str[k];
						k++;
						p++;
				}
				int n;
				//if(num[0] != ' ' || num[0] != '\n')
				printf("%s ",num);
				n = to_num(num);
				printf("%d ",n);
				//train_array[i].starr[j].data.id = n;
				//strcpy(train_array[i].starr[j].data.name,station_array[n].data.name);
				//printf("%s\n",station_array[n].data.name);
				if(str[k] == ' '||str[k] == '\0' || str[k] == '\n')
				{
					k++;
				}
				//j++;
				
			}
			//train_array[i].station_size = j;
			i++;
		}
		
	}
	return 0;
}*/
