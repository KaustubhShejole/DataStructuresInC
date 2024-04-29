#include"InsertNode.h"
extern int id;
extern Node* Record_List;
Node* InsertAtList(Node* nptr,Node* lptr)
{
	int key;
	key = nptr->data.train_id;
  if(lptr==NULL)
    {
      nptr->next = NULL;
      lptr = nptr;
    }
  else
    {
    	Node* ptr;
    	ptr = lptr;
    	int status;
    	status = 0;
    	for(;ptr->next != NULL && status==0;ptr=ptr->next)
    	{
			if(key<=(ptr->next->data).train_id)
			{
				
				nptr->next = ptr->next;
				ptr->next = nptr;
				status = 1;
			}
		}
		if(status==0 && ptr->next==NULL)
		{
			if(key<=(ptr->data).train_id)
			{
				lptr = nptr;
				nptr->next = ptr;
				status = 1;
			}
			else
			{
				ptr->next = nptr;
				nptr->next = NULL;
			}
		}
    		
    }
  return lptr;
}
Node* InsertAtEnd(Node* nptr,Node* lptr)
{
  if(lptr==NULL)
    {
      nptr->next = NULL;
      lptr = nptr;
    }
  else
    {
      Node* ptr;
      ptr = lptr;
      while((ptr->next)!=NULL)
	{
	  ptr=ptr->next;
	}
      ptr->next = nptr;
      nptr->next = NULL;
    }
  return lptr;
}
Node* DeleteList(Node* lptr)
{
  Node* nptr;
  nptr = lptr;
  while(lptr!=NULL)
    {
      //printf("Deleted a node with value of data in a node %d\n",lptr->data);
      lptr=lptr->next;
      free(nptr);
      nptr=lptr;
    }
  return lptr;
}
int give_pname(int pid,char* s)
{
	int ret_val;
	ret_val = 0;
	Node* nptr;
	nptr = Record_List;
	if(nptr!=NULL)
	{
		for(nptr = Record_List;nptr->data.pid!=pid && nptr->next!=NULL;nptr=nptr->next)
		{
		}
		if(nptr->data.pid==pid)
		{
			strcpy(s,nptr->data.pname);
			ret_val = 1;
		}
	}
	return ret_val;
}

void print_tclass(travel_class t)
{
	printf("Travelling Class : ");
	switch(t)
	{
		case 0: printf("Sleeper\n");
		break;
		case 1:printf("3AC\n");
		break;
		case 2: printf("2AC\n");
		break;
		case 3:printf("1AC\n");
		break;
	}
}
void AddSub_list(Node* sub_lptr)
{
	Node* end;
	end = NULL;
	Node* nptr;
	nptr = sub_lptr;
	for(;nptr!=NULL;nptr=nptr->next)
	{
		if(nptr->next == NULL)
		{
			end = nptr;
		}
	}
	//now we have start as well as end
	Node* lptr;
	lptr = Record_List;
	if(lptr!=NULL)
	{
		if(lptr->next == NULL)
		{
			if((lptr->data).train_id > (sub_lptr->data).train_id)
			{
				end->next = lptr;
				Record_List = sub_lptr;
			}
			else
			{
				lptr->next = sub_lptr;
			}
		}
		else
		{
			int key;
			int status;
			status = 0;
			key = sub_lptr->data.train_id;
			Node* prev;
			prev = NULL;
			if(key<=(lptr->data).train_id)
			{
				end->next = lptr;
				Record_List = sub_lptr;
			}
			else
			{
				for(;lptr->next != NULL && status==0;lptr=lptr->next)
				{
					if(key<=(lptr->next->data).train_id)
					{
						end->next = lptr->next;
						lptr->next = sub_lptr;
						status = 1;
					}
					prev=lptr;
				}
				if(status==0 && lptr->next==NULL)
				{
					if(prev!=NULL && key<=(lptr->data).train_id)
					{
						prev->next = sub_lptr;
						end->next = lptr;
						status = 1;
					}
					else
					{
						lptr->next = sub_lptr;
						end->next = NULL;
					}
				}
			}
		}
	}
	else
	{
		Record_List = sub_lptr;
	}
}