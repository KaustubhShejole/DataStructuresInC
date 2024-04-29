#ifndef STORESTATIONS_H
#define STORESTATIONS_H
#include<stdio.h>
typedef struct record_tag
{
	int id;
	char name[80];
}record;
typedef struct Station_tag
{
    record data;
}Station;
int station_size;
Station* station_array;

void StoreStations();
void DisplayStations();
void ShowStations(int);
#endif
