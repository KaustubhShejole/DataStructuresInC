#include"Insertion.h"
extern Tree_Node* Record_Root;
void getListDestination(Node* nptr)
{
    int snum,tnum;
    snum = nptr->data.dstat_num;
    tnum = nptr->data.train_id;
    printf("\t\t*****************List of people with train as %s \n\t\t\tand with destination station %s\t\t****************\n",nptr->data.tname,nptr->data.dstation);
    while(nptr!=NULL)
    {
        int ssnum,ttnum;
        ssnum = nptr->data.dstat_num;
        ttnum = nptr->data.train_id;
        while(ssnum == snum && ttnum == tnum &&nptr!=NULL)
        {
            printf("\t\tPassenger with %d id and %s name\n",nptr->data.pid,nptr->data.pname);
            nptr=nptr->next;
            if(nptr!=NULL)
            {
                ssnum = nptr->data.dstat_num;
                ttnum = nptr->data.train_id;
            }
        }
        if(nptr!=NULL)
            nptr=nptr->next;
    }
}
void getTreeDestinationHelper(Tree_Node* root)
{
    if(root!=NULL)
    {
        getTreeDestinationHelper(root->left);
        getListDestination(root->lptr);
        getTreeDestinationHelper(root->right);
    }
}
void getTreeDestination()
{
    Tree_Node* root;
    root=Record_Root;
    getTreeDestinationHelper(root);
    printf("\n\n");
}