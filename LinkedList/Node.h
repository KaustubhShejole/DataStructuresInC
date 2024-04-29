#ifndef NODE_H
#define NODE_H
#include<stdio.h>
#include"general.h"
typedef struct date_tag
{
    int dd,mm,yy;
}date;
typedef struct passenger_record_tag
{
    date d;
    char pname[80];
    int pid;
    char tname[80];
    int bstat_num;
    char bstation[80];
    travel_class tclass;
    int dstat_num;
    char dstation[80];
    int train_id;
    int bogie_number;
    int seat_number;
    Boolean upgrade;
}P_record;
typedef P_record  Itemtype;
typedef struct Node_tag
{
	Itemtype data;
	struct Node_tag* next;
}Node;
void DisplayNode(Node* n);
#endif
