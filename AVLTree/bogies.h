#include<stdio.h>
#define AC1_size 24
#define AC2_size 48
#define AC3_size 64
#define S_size 72
typedef struct seat_tag
{
	int seat_num;
}seat;
typedef struct bogie_seat_tag
{
	int start;
	int end;
	struct bogie_seat_tag* next;
}bogie_seat;
typedef struct bogie_tag
{
	bogie_seat* filled_seat_list;
	bogie_seat* free_seat_list;
}Bogie_Node;
typedef struct S_bogie_tag
{
	Bogie_Node s;
}S_bogie;
typedef struct AC1_bogie_tag
{
	Bogie_Node ac1;
}AC1_bogie;
typedef struct AC2_bogie_tag
{
	Bogie_Node ac2;
}AC2_bogie;
typedef struct AC3_bogie_tag
{
	Bogie_Node ac3;
}AC3_bogie;