#ifndef RESERVATION_H
#define RESERVATION_H
#include"Insertion.h"
void Append(int start,int end,bogie_seat* bogie_list);
int CheckAC1(Node*,int num,int train_index);
int CheckAC2(Node*,int num,int train_index);
int CheckAC3(Node*,int num,int train_index);
int CheckS(Node* ,int num,int train_index);
bogie_seat* AppendInFilledList(int,int,int,int,travel_class t);
int CheckAvailabilityAC1(Node* sub_lptr,int num,int train_index,int i);
int CheckAvailabilityAC2(Node* sub_lptr,int num,int train_index,int i);
int CheckAvailabilityAC3(Node* sub_lptr,int num,int train_index,int i);
int CheckAvailabilityS(Node*,int,int,int);
void Give_Seat_Numbers(Node* sub_lptr,int start,int end,int index);
void DisplayLIST(bogie_seat* b);
int CheckFreeSeats(int,travel_class);
void DoReservation(Node*,int,int,travel_class);
int partial_reservation_helper(Node* sub_lptr,int num1,int train_index,int status,travel_class t);

#endif