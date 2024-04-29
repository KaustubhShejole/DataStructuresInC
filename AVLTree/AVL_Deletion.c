#include"TreeNode.h"
#include"AVL_functions.h"
#include<stdlib.h>
Tree_Node* SearchForDelete(Tree_Node* root,int value,Boolean* shorter,Tree_Node* Root);
Tree_Node* AVL_Delete(Tree_Node* root,int value)
{
    Boolean shorter;
    shorter = TRUE;
    root = SearchForDelete(root,value,&shorter,root);
    return root;
}
void DeleteTreeNode(Tree_Node** ptr,Boolean* shorter,Tree_Node* Root)
{
    if(ptr==NULL)
    {
        printf("Not possible\n");
    }
    else if((*ptr)->left==NULL)
    {
        Tree_Node* temp = (*ptr);
        (*ptr) = (*ptr)->right;
        free(temp);
        temp = NULL;
    }
    else if((*ptr)->right == NULL)
    {
        Tree_Node* temp = (*ptr);
        (*ptr) = (*ptr)->left;
        free(temp);
        temp = NULL;
    }
    else//two children case
    {
        Tree_Node* p;
        p = *ptr;
        Tree_Node* q;
        q = p->left;
        /*Tree_Node* parent;
        parent = p->left;*/
        while(q->right!=NULL)
        {
            //parent = q;
            q=q->right;
        }
        //Itemtype temp_data;
        int temp_key;
        Node* temp_lptr;
        temp_key = p->key;
        p->key = q->key;
        q->key = temp_key;
        temp_lptr = p->lptr;
        p->lptr = q->lptr;
        q->lptr = temp_lptr;
        (*ptr)->left = SearchForDelete(Root->left,temp_key,shorter,Root);
        /*if(p->left == q)//p->left->right==NULL
        {
            //attach p->left->right to p->right
            //free(p);
            q->right = p->right;
            (*ptr) = q;
            free(p);
            p = NULL;
        }
        else
        {
            parent->right = q->left;
            q->right = p->right;
            q->left = p->left;
            (*ptr) = q;
            free(p);
            p=NULL;
        }*/
    }
}
Tree_Node* SearchForDelete(Tree_Node* root,int value,Boolean* shorter,Tree_Node* Root)
{
    if(root==NULL)
    {
        printf("Value Not Foud!");
    }
    else if(root->key == value)
    {
        DeleteTreeNode(&root,shorter,Root);
    }
    else if(root!=NULL && root->key < value)
    {
        if(root->right!=NULL && root->right->key == value)
        {
            DeleteTreeNode(&root->right,shorter,Root);
            if(*shorter)
            {
                root = RightDeletionBalance(root,shorter);
            }
        }
        else
        {
            root->right = SearchForDelete(root->right,value,shorter,Root);
            if(*shorter)
            {
                root = RightDeletionBalance(root,shorter);
            }
        }
    }
    else if(root!=NULL && root->key > value )
    {
        if(root->left != NULL && root->left->key == value)
        {
            DeleteTreeNode(&root->left,shorter,Root);
            if(*shorter)
            {
                root = LeftDeletionBalance(root,shorter);
            }
        }
        else
        {
            root->left = SearchForDelete(root->left,value,shorter,Root);
            if(*shorter)
            {
                root = LeftDeletionBalance(root,shorter);
            }
        }
    }
    return root;
}