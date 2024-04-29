#ifndef INSERTNODE_H
#define INSERTNODE_H

#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "general.h"
#include "Node.h"
#include "storestations.h"
#include "storetrains.h"
#include "reservation.h"
extern Station* station_array;
extern Train* train_array;
extern int train_size;
extern int station_size;
Node* InsertAtList(Node* nptr,Node* lptr);
Boolean found_station(int key,int train_id,int start);
Boolean is_last(int i,int train_id);
Node* InsertAtEnd(Node* nptr,Node* lptr);
int give_pname();
int scan_station_id(int train_id,int start,int bbb);
void DisplayTrainNames();
int train_found(int key);
void InsertList();
void DisplayRecord(Itemtype* r);
void DisplayInRecordFile(Itemtype* r,FILE* );
void Insert();
void DisplayList(Node* lptr);
Node* DeleteList(Node* lptr);
int reservation(Node*,int,int);
void print_tclass(travel_class t);
int give_pname(int pid,char* s);
void AddSub_list(Node* sub_lptr);
void StoreRecords();
void getListDestination();
void print_date(date d);
void SortTrains();
void date_cpy(date* d1,date* d2);
Boolean is_equal_date(date d1,date d2);
void SortByTravelDate();
bogie_seat* InserAtBogieEnd(int,int,bogie_seat*);
Node* DeleteNode();
Boolean valid_date(date d);
date scan_date();
bogie_seat* RemovefromFilledList(int value,int train_index,int i,travel_class t);
bogie_seat* AddToFreeList(int start,int end,int i,int train_index,travel_class t);
Node* PromotePassengers();
#endif
