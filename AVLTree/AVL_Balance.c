#include"TreeNode.h"
#include"AVL_functions.h"
Tree_Node* RightBalance(Tree_Node* Root,Boolean* taller)
{
    Tree_Node* rs = Root->right;
    Tree_Node* ls;
    ls=NULL;
    if(rs!=NULL)
    {
        switch(rs->bf)
        {
            case RH:
                Root->bf = EH;
                rs->bf = EH;
                Root = RotateLeft(Root);
                *taller = FALSE;
                break;
            case EH:
                printf("Already Balanced");
                break;
            case LH:
                ls = rs->left;
                if(ls!=NULL)
                {
                    switch(ls->bf)
                    {
                        case RH:
                            Root->bf = LH;
                            rs->bf = EH;
                            break;
                        case EH:
                            Root->bf = EH;
                            rs->bf=EH;
                            break;
                        case LH:
                            Root->bf = EH;
                            rs->bf = EH;
                            break;
                    }
                }
                ls->bf = EH;
                Root->right = RotateRight(rs);
                Root = RotateLeft(Root);
                *taller = FALSE; 
                break;       
        }
    }
    return Root;
}
Tree_Node* LeftBalance(Tree_Node* Root,Boolean* taller)
{
    Tree_Node* ls = Root->left;
    Tree_Node* rs;
    rs=NULL;
    if(ls!=NULL)
    {
        switch(ls->bf)
        {
            case RH:
                Root->bf = EH;
                ls->bf = EH;
                Root = RotateRight(Root);
                *taller = FALSE;
                break;
            case EH:
                printf("Already Balanced");
                break;
            case LH:
                rs = ls->right;
                if(rs!=NULL)
                {
                    switch(rs->bf)
                    {
                        case RH:
                            Root->bf = LH;
                            ls->bf = EH;
                            break;
                        case EH:
                            Root->bf = EH;
                            ls->bf=EH;
                            break;
                        case LH:
                            Root->bf = EH;
                            rs->bf = EH;
                            break;
                    }
                    rs->bf = EH;
                }
                Root->left = RotateLeft(ls);
                Root = RotateRight(Root);
                *taller = FALSE; 
                break;       
        }
    }
    return Root;
}