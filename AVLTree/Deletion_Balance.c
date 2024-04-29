#include"TreeNode.h"
#include"AVL_functions.h"

Tree_Node* LeftDeletionBalance(Tree_Node* root,Boolean* shorter)
{
    if(root->bf == EH)
    {
        root->bf = RH;
        *shorter = FALSE;
    }
    else if(root->bf == LH)//taller subtree shortened
    {
        root->bf = EH;
    }
    else if(root->bf == RH)//shorter subtree shortened
    {
        Tree_Node* q;
        q = root->right;//q is the root of taller subtree
        if(q->bf == EH)
        {
            q->bf = LH;
            root = RotateLeft(root);
            *shorter = FALSE;
        }
        else if(q->bf == RH)
        {
            q->bf = EH;
            root->bf = EH;
            root = RotateLeft(root);
        }
        else if(q->bf == LH)
        {
            //balance factor of root and q are opposite
            Tree_Node* r;
            r = q->left;
            switch(r->bf)
            {
                case EH:
                root->bf = EH;
                q->bf = EH;
                break;
                case RH:
                root->bf = LH;
                q->bf = EH;
                r->bf = EH;
                break;
                case LH:
                root->bf = EH;
                q->bf = RH;
                r->bf = EH;
            }
            root->right = RotateRight(root->right);
            root = RotateLeft(root);
        }
    }
    return root;
}
Tree_Node* RightDeletionBalance(Tree_Node* root,Boolean* shorter)
{
    if(root->bf == EH)
    {
        root->bf = LH;
        *shorter = FALSE;
    }
    else if(root->bf == RH)//taller subtree shortened
    {
        root->bf = EH;
    }
    else if(root->bf == LH)//shorter subtree shortened
    {
        Tree_Node* q;
        q = root->left;//q is the root of taller subtree
        if(q->bf == EH)
        {
            q->bf = RH;
            root = RotateRight(root);
            *shorter = FALSE;
        }
        else if(q->bf == LH)
        {
            q->bf = EH;
            root->bf = EH;
            root = RotateRight(root);
        }
        else if(q->bf == RH)//root and q have opposite balance factors
        {
            Tree_Node* r;
            r = q->right;
            switch(r->bf)
            {
                case EH:
                root->bf = EH;
                q->bf = EH;
                break;
                case LH:
                q->bf = EH;
                root->bf = RH;
                r->bf = EH;
                break;
                case RH:
                q->bf = LH;
                root->bf = EH;
                r->bf = EH;
                break;
            }
            root->left = RotateLeft(root->left);
            root = RotateRight(root);
        }
    }
    return root;
}