#ifndef TREENODE_H
#define TREENODE_H
#include<stdio.h>
#include"general.h"
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
typedef enum balance_factor_tag{LH,EH,RH} Balance_Factor_type;
typedef struct Node_tag
{
	Itemtype data;
	struct Node_tag* next;
}Node;
typedef struct tree_node_tag
{
    Balance_Factor_type bf;
    int key;//key is train_id because we have to sort data according to train_id
    Node* lptr;
    struct tree_node_tag *left;
    struct tree_node_tag *right;
}Tree_Node;
void DisplayNode(Tree_Node*);
#endif
