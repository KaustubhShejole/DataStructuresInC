#include<stdio.h>
#include<stdlib.h>
#include"TreeNode.h"
#include"Insertion.h"
extern Tree_Node* Record_Root;
extern int id;
void DisplayInRecordFile(Itemtype* r,FILE* fp)
{
	fprintf(fp,"%d ",(r->pid));
    fprintf(fp,"%s\n",(r->pname));
    fprintf(fp,"%d ",r->train_id);
    fprintf(fp,"%s\n",r->tname);
    
    fprintf(fp,"%d ",r->bstat_num);
    fprintf(fp,"%s\n",r->bstation);
    
    fprintf(fp,"%d ",r->dstat_num);
    fprintf(fp,"%s\n",r->dstation);
	fprintf(fp,"%d %d %d %d\n",r->tclass,r->bogie_number,r->seat_number,r->upgrade);
	fprintf(fp,"%d %d %d\n",r->d.dd,r->d.mm,r->d.yy);
}
void StoreRecords()
{
	FILE* fp;
	fp = fopen("records.txt","r");
	char str[90];
	int i;
	i=0;
	int d;
	char s[90];
	Node* nptr;
	int status=0;
	nptr = (Node*)malloc(sizeof(Node));
	while(fgets(str,90,fp))
	{
		status=1;
		switch(i)
		{
			case 0:
			case 1:
			case 2:
			case 3:
				sscanf(str,"%d %[^\n]s",&d,s);
				switch(i)
				{
					case 0: nptr->data.pid = d;
					strcpy(nptr->data.pname,s);
					break;
					case 2:nptr->data.bstat_num=d;
					strcpy(nptr->data.bstation,s);
					break;
					case 3:nptr->data.dstat_num = d;
					strcpy(nptr->data.dstation,s);
					break;
					case 1:
					nptr->data.train_id = d;
					strcpy(nptr->data.tname,s);
				}
			break;
			case 4:
				sscanf(str,"%d %d %d %d",&(nptr->data.tclass),&(nptr->data.bogie_number),&(nptr->data.seat_number),&(nptr->data.upgrade));
				
			break;
			case 5:
				sscanf(str,"%d %d %d",&(nptr->data.d.dd),&(nptr->data.d.mm),&(nptr->data.d.yy));
			break;
		}
		if(i==5)
		{
			i=0;
			nptr->next=NULL;
			Record_Root=Insert_List_In_Tree(Record_Root,nptr);
			//DisplayRecord(&nptr->data);
			nptr = (Node*)malloc(sizeof(Node));
			id++;
			status=0;
		}
		else
		{
			i=i+1;
		}
	}
	if(status==0)
	{
		free(nptr);
	}
	fclose(fp);
	DisplayTree(Record_Root);
}
void DisplayListInRecordFile(Node* nptr,FILE* fp)
{
	while(nptr!=NULL)
	{
		DisplayInRecordFile(&nptr->data,fp);
		nptr=nptr->next;
	}
}
void DisplayTreeInFileHelper(Tree_Node* root,FILE* fp)
{
	if(root!=NULL)
	{
		DisplayTreeInFileHelper(root->left,fp);
		DisplayListInRecordFile(root->lptr,fp);
		DisplayTreeInFileHelper(root->right,fp);
	}
}
void DisplayTreeInRecordFile()
{
	FILE* fp;
	fp = fopen("records.txt","w");
	Tree_Node* root;
	root = Record_Root;
	DisplayTreeInFileHelper(root,fp);
	fclose(fp);
}