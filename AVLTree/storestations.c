#include<stdio.h>
#include "storestations.h"
#include<string.h>
#include<stdlib.h>
#include"storetrains.h"
extern Train* train_array;
void StoreStations()
{
	char str[80];
	FILE *fp = fopen("stations.txt","r");
	int i = 0;
	while(fgets(str,80,fp))
	{
		i++;
	}
	fclose(fp);
	station_size = i;
	station_array = (Station*)malloc((sizeof(Station))*i);
	int id;
	char name[80];
	fp = fopen("stations.txt","r");
	i=0;
	while(fgets(str,80,fp))
	{
		sscanf(str,"%d %[^\n]s ",&id,name);
		station_array[i].data.id = id;
		strcpy(station_array[i].data.name,name);
		i++;
	}
	fclose(fp);
}
void ShowStation(Station x)
{
	printf("%d %s",x.data.id,x.data.name);
	printf("\n");
}
void DisplayStations()
{
	int i = 0;
	while(i<station_size)
	{
		ShowStation(station_array[i]);
		i++;
	}
}
void ShowStations(int train_index)
{
	printf("Stations of this train with %d id\n",train_index);
	int status=0;
	int i;
	for(i=0;status==0&&i<train_size;i++)
	{
		if(train_index == train_array[i].data.id)
		{
			status=1;
		}
	}
	train_index = i-1;
	i = 0;
	int j = train_array[train_index].station_size;
	while(i<j)
	{
		ShowStation(train_array[train_index].starr[i]);
		i++;
	}
}