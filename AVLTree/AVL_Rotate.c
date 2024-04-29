#include"TreeNode.h"
Tree_Node* RotateLeft(Tree_Node* Root)
{
    Tree_Node* temp;
    temp = Root;
    if(Root == NULL)
    {
        printf("We cannot rotate an empty tree");
    }
    else if(Root->right == NULL)
    {
        printf("We Cannot rotate left");
    }
    else
    {
        temp = Root->right;
        Root->right = temp->left;
        temp->left = Root;
    }
    return temp;
}
Tree_Node* RotateRight(Tree_Node* Root)
{
    Tree_Node* temp;
    temp = Root;
    if(Root == NULL)
    {
        printf("We cannot rotate an empty tree");
    }
    else if(Root->left == NULL)
    {
        printf("We Cannot rotate left");
    }
    else
    {
        temp = Root->left;
        Root->left = temp->right;
        temp->right = Root;
    }
    return temp;
}