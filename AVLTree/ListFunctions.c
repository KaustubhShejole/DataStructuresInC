#include"Insertion.h"
extern int id;
void DisplayList(Node* lptr)
{
	while(lptr!=NULL)
	{
		DisplayRecord(&(lptr->data));
		printf("\n");
		lptr = lptr->next;
	}
}
Node* InsertatListEnd(Node* lptr,Node* nptr)
{
    Node* ptr;
    ptr=lptr;
    if(ptr!=NULL)
    {
        while(ptr->next!=NULL)
        {
          ptr=ptr->next;
        }
        ptr->next=nptr;
    }
    else
    {
        lptr=nptr;
    }
    return lptr;
}
Node* InsertAtEnd(Node* lptr,Node* nptr)
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