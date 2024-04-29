#include"TreeNode.h"
#include"Insertion.h"
#include"AVL_functions.h"
Tree_Node* InsertlistinTree(Tree_Node* Root,Node* lptr,Boolean* taller);
Tree_Node* Insert_AVL_data(Tree_Node* Root,Itemtype item_value,Boolean* taller);
Tree_Node* InsertNode(Tree_Node* Root,Node* nptr)
{
    Itemtype data = nptr->data;
    Boolean taller;
    taller = FALSE;
    Root = Insert_AVL_data(Root,data,&taller);
    return Root;
}

Tree_Node* Insert_List_In_Tree(Tree_Node* Root,Node* lptr)
{
    Boolean taller;
    taller = FALSE;
    Root = InsertlistinTree(Root,lptr,&taller);
    return Root;
}
Tree_Node* InsertlistinTree(Tree_Node* Root,Node* lptr,Boolean* taller)
{
    if(Root==NULL)
    {
        Root = (Tree_Node*)malloc(sizeof(Tree_Node));
        Root->key = lptr->data.train_id;
        /*Node* nptr;
        nptr = (Node*)malloc(sizeof(Node));
        nptr->data=item_value;
        nptr->next = NULL;
        Root->lptr = InsertAtEnd(Root->lptr,nptr);*/
        //printf("Created node with value %d\n",Root->data);
        Root->lptr=lptr;
        Root->bf = EH;
        Root->right = NULL;
        Root->left = NULL;
        *taller = TRUE;
    }
    else if(Root->key == lptr->data.train_id)//Equal
    {
        //printf("Equal values");
        //printf("\n")s
        Root->lptr =InsertatListEnd(Root->lptr,lptr);
        *taller = FALSE;
    }
    else if(Root->key>lptr->data.train_id)//Root->key greater than item_value.train_id
    {
        Root->left=InsertlistinTree(Root->left,lptr,taller);
        if(*taller)//Left Subtree is Taller
        {
            switch (Root->bf)
            {
                case EH:
                    Root->bf = LH;
                    break;
                case RH:
                    Root->bf = EH;
                    *taller = FALSE;
                    break;
                case LH:
                    Root = LeftBalance(Root,taller);
                    break;
            }
        }
    }
    else
    {
        Root->right = InsertlistinTree(Root->right,lptr,taller);
        if(*taller)//Right Subtree is Taller
        {
            switch (Root->bf)
            {
                case EH:
                    Root->bf = RH;
                    break;
                case LH:
                    Root->bf = EH;
                    *taller = FALSE;
                    break;
                case RH:
                    Root = RightBalance(Root,taller);
                    break;
            }
        }
    }
    return Root;
}
int compare_Itemtype(Itemtype r1,Itemtype r2)
{
    if(r1.train_id==r2.train_id && r1.pid==r2.pid && r1.bstat_num==r2.bstat_num && r1.dstat_num==r2.dstat_num && is_equal_date(r1.d,r2.d))
    {
        return 0;
    }
    else if(r1.train_id>r2.train_id || r1.pid>r2.pid || r1.bstat_num>r2.bstat_num || r1.dstat_num>r2.dstat_num || !(is_equal_date(r1.d,r2.d)))
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
Tree_Node* Insert_AVL_data(Tree_Node* Root,Itemtype item_value,Boolean* taller)
{
    if(Root==NULL)
    {
        Root = (Tree_Node*)malloc(sizeof(Tree_Node));
        Root->key = item_value.train_id;
        Node* nptr;
        nptr = (Node*)malloc(sizeof(Node));
        nptr->data=item_value;
        nptr->next = NULL;
        Root->lptr = InsertAtEnd(Root->lptr,nptr);
        //printf("Created node with value %d\n",Root->data);
        Root->bf = EH;
        Root->right = NULL;
        Root->left = NULL;
        *taller = TRUE;
    }
    else if(Root->key == item_value.train_id)//Equal
    {
        //printf("Equal values");
        //printf("\n")
        Node* nptr;
        nptr = (Node*)malloc(sizeof(Node));
        nptr->next=NULL;
        nptr->data = item_value;
        Root->lptr=InsertAtEnd(Root->lptr,nptr);
        *taller = FALSE;
    }
    else if(Root->key>item_value.train_id)//Root->key greater than item_value.train_id
    {
        Root->left=Insert_AVL_data(Root->left,item_value,taller);
        if(*taller)//Left Subtree is Taller
        {
            switch (Root->bf)
            {
                case EH:
                    Root->bf = LH;
                    break;
                case RH:
                    Root->bf = EH;
                    *taller = FALSE;
                    break;
                case LH:
                    Root = LeftBalance(Root,taller);
                    break;
            }
        }
    }
    else
    {
        Root->right = Insert_AVL_data(Root->right,item_value,taller);
        if(*taller)//Right Subtree is Taller
        {
            switch (Root->bf)
            {
                case EH:
                    Root->bf = RH;
                    break;
                case LH:
                    Root->bf = EH;
                    *taller = FALSE;
                    break;
                case RH:
                    Root = RightBalance(Root,taller);
                    break;
            }
        }
    }
    return Root;
}