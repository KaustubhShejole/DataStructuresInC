#include"Insertion.h"
#include<string.h>
#include"AVL_functions.h"
extern int id;
extern Tree_Node* Record_Root;
Tree_Node* CreateNode(Itemtype item)
{
    Tree_Node* p;
    p = (Tree_Node*)malloc(sizeof(Tree_Node));
    if(p!=NULL)
    {
		p->lptr = (Node*)malloc(sizeof(Node));
        p->lptr->data = item;
        p->left = NULL;
        p->right = NULL;
    }
    else
    {
        printf("Insufficient Memory");
    }
    return p;
}
Tree_Node* DeleteTree(Tree_Node* Root)
{
    if(Root!=NULL)
    {
        Root->left = DeleteTree(Root->left);
        Root->right = DeleteTree(Root->right);
            
        //DisplayRecord(&(Root->data));
		DeleteList(Root->lptr);
        free(Root);
        Root = NULL;
    }
    return Root;
}
void DisplayTree(Tree_Node* root)
{
	if(root!=NULL)
	{
		DisplayTree(root->left);
		DisplayList(root->lptr);
		DisplayTree(root->right);
	}
}
int give_Pname(Node* lptr,int pid,char* s)
{
	Boolean found;
	found = FALSE;
	while(lptr!=NULL && !found)
	{
		if(lptr->data.pid==pid)
		{
			found=TRUE;
			strcpy(s,lptr->data.pname);
		}
		lptr=lptr->next;
	}
	return found;
}
int give_pname_status(Tree_Node* root,int pid,char* s)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		if(give_Pname(root->lptr,pid,s))
		{
			return 1;
		}
		int ret_val;
		ret_val = 0;
		ret_val = give_pname_status(root->right,pid,s);
		if(ret_val==0)
		{
			ret_val = give_pname_status(root->left,pid,s);
		}
		return ret_val;
	}
}
int give_pname(int pid,char* s)
{
	int ret_val;
	ret_val=0;

	Tree_Node* root;
	root = Record_Root;
	ret_val = give_pname_status(root,pid,s);
	return ret_val;
}
Tree_Node* DeleteAllRecordsWithPid(Tree_Node* root,int pid)
{
	if(root!=NULL)
	{
		Node* nptr;
        Node* ptr;
        nptr=root->lptr;
        ptr=nptr;
        if(nptr->data.pid== pid)
        {
            root->lptr = root->lptr->next;
            free(nptr);
        }
		int status=0;
        while(nptr->next!=NULL && status==0)
        {
            if (nptr->next->data.pid == pid)
            {
                ptr=nptr->next;
                nptr->next = nptr->next->next;
                free(ptr);
            }
            if(ptr->next!=NULL)
            {
                //nptr=nptr->next;
            }
			else
			{
				status = 1;
			}
        }
		if(root->lptr==NULL)
		{
			Record_Root = AVL_Delete(Record_Root,root->key);
		}
		root->right = DeleteAllRecordsWithPid(root->right,pid);
		root->left = DeleteAllRecordsWithPid(root->left,pid);	
	}
	return root;
}