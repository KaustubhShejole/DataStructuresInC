#ifndef INSERTION_H
#define INSERTION_H

#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "general.h"
#include "TreeNode.h"
//#include"Node.h"
#include "storestations.h"
#include "storetrains.h"
//#include "reservation.h"
#include"TreeNode.h"
#include"ListFunctions.h"
extern Station* station_array;
extern Train* train_array;
extern int train_size;
extern int station_size;
Boolean found_station(int key,int train_id,int start);
Boolean is_last(int i,int train_id);
int scan_station_id(int train_id,int start,int bbb);
void DisplayTrainNames();
int train_found(int key);
void print_tclass(travel_class t);
int give_Pname(Node* lptr,int pid,char* s);
int give_pname(int pid,char* s);
void print_date(date d);
void date_cpy(date* d1,date* d2);
Boolean is_equal_date(date d1,date d2);
void DisplayRecord(Itemtype* r);
void DisplayInRecordFile(Itemtype* r,FILE* );
Boolean valid_date(date d);
date scan_date();

Tree_Node* InsertNode(Tree_Node* Root,Node* nptr);
void InsertList();
void Insert();
Tree_Node* Insert_List_In_Tree(Tree_Node* Root,Node* lptr);
/*Inserts lptr list at correct position in a Tree*/
void DisplayTree(Tree_Node*);
Tree_Node* DeleteTree(Tree_Node* Root);
int reservation(Node*,int,int);
void StoreRecords();
void getTreeDestination();
void SortTrains();
void SortByTravelDate();
//bogie_seat* InsertAtBogieEnd(int,int,bogie_seat*);
Tree_Node* DeleteNode();
bogie_seat* RemovefromFilledList(int value,int train_index,int i,travel_class t);
bogie_seat* AddToFreeList(int start,int end,int i,int train_index,travel_class t);
Tree_Node* DeleteAllRecordsWithPid(Tree_Node* root,int pid);
void DisplayTreeInRecordFile();
int compare_date(date d1,date d2);
void RangeSearch();
#endif
