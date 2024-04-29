#ifndef GENERAL_H
#define GENERAL_H
#include<stdio.h>
#include<string.h>
#include"storestations.h"
#include"storetrains.h"

typedef enum class_tag{Sleeper,AC3,AC2,AC1} travel_class;
typedef enum boolean_tag{FALSE,TRUE} Boolean;
extern Station* station_array;
extern Train* train_array;

typedef struct train_tag
{
    int id;
    char name[80];
}train;
typedef struct date_tag
{
    int dd,mm,yy;
}date;
#endif
