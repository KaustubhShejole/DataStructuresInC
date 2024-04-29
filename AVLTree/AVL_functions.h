#ifndef AVLFUN_H
#define AVLFUN_H

Tree_Node* LeftBalance(Tree_Node* Root,Boolean* taller);
Tree_Node* RightBalance(Tree_Node* Root,Boolean* taller);
Tree_Node* RotateRight(Tree_Node* Root);
Tree_Node* RotateLeft(Tree_Node* Root);
Tree_Node* RightDeletionBalance(Tree_Node* root,Boolean* shorter);
Tree_Node* LeftDeletionBalance(Tree_Node* root,Boolean* shorter);
Tree_Node* AVL_Delete(Tree_Node* root,int value);
#endif