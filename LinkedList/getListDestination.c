#include"InsertNode.h"
extern Node* Record_List;
void getListDestination()
{
    Node* nptr;
    nptr=Record_List;
    int snum,tnum;
    snum = nptr->data.dstat_num;
    tnum = nptr->data.train_id;
    printf("List of people with train as %s \nand with destination station %s\n",nptr->data.tname,nptr->data.dstation);
    while(nptr!=NULL)
    {
        int ssnum,ttnum;
        ssnum = nptr->data.dstat_num;
        ttnum = nptr->data.train_id;
        while(ssnum == snum && ttnum == tnum &&nptr!=NULL)
        {
            printf("Passenger with %d id and %s name\n",nptr->data.pid,nptr->data.pname);
            nptr=nptr->next;
            if(nptr!=NULL)
            {
                ssnum = nptr->data.dstat_num;
                ttnum = nptr->data.train_id;
            }
        }
        if(nptr!=NULL &&(!(ssnum==snum&&ttnum==tnum)))
        {
            snum=ssnum;
            tnum=ttnum;
            printf("\nList of people with train as %s \nand with destination station %s\n",nptr->data.tname,nptr->data.dstation);
    
        }
    }
}