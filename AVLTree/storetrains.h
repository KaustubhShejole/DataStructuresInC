#ifndef STORETRAINS_H
#define STORETRAINS_H
#include<stdio.h>
#include "storestations.h"
#include "bogies.h"
typedef struct Train_tag
{
    record data;
    Station* starr;
    int station_size;
    int bogies[4];
    AC1_bogie* AC1_bogies;
    AC2_bogie* AC2_bogies;
    AC3_bogie* AC3_bogies;
    S_bogie* S_bogies;
}Train;
Train* train_array;
int train_size;
void StoreTrains();
void DisplayTrains();
void Delete(Train*);
#endif
