/*
    QUESTION :
        Given an array of elements, construct a complete binary tree from this array in level order
        fashion. That is, elements from left in the array will be filled in the tree level wise starting from
        level 0. Ex: Input :
        arr[] = {1, 2, 3, 4, 5, 6}
        Output : Root of the following tree
                1
               / \
              2   3
             / \ / \
            4    5  6
    OUTPUT :
        MENU - 1:Insert, 2:Preorder, 3:Inorder, 4:Postorder, 5:Exit
        Enter your choice : 1
        Enter element to insert : 10
        
        MENU - 1:Insert, 2:Preorder, 3:Inorder, 4:Postorder, 5:Exit
        Enter your choice : 1
        Enter element to insert : 5
        Enter the direction to insert (say 'l' or 'r') : l
        
        MENU - 1:Insert, 2:Preorder, 3:Inorder, 4:Postorder, 5:Exit
        Enter your choice : 1
        Enter element to insert : 3
        Enter the direction to insert (say 'l' or 'r') : ll
        
        MENU - 1:Insert, 2:Preorder, 3:Inorder, 4:Postorder, 5:Exit
        Enter your choice : 1
        Enter element to insert : 2
        Enter the direction to insert (say 'l' or 'r') : lll
        
        MENU - 1:Insert, 2:Preorder, 3:Inorder, 4:Postorder, 5:Exit
        Enter your choice : 1
        Enter element to insert : 6
        Enter the direction to insert (say 'l' or 'r') : lr
        
        MENU - 1:Insert, 2:Preorder, 3:Inorder, 4:Postorder, 5:Exit
        Enter your choice : 1
        Enter element to insert : 15
        Enter the direction to insert (say 'l' or 'r') : r
        
        MENU - 1:Insert, 2:Preorder, 3:Inorder, 4:Postorder, 5:Exit
        Enter your choice : 1
        Enter element to insert : 12
        Enter the direction to insert (say 'l' or 'r') : rl
        
        MENU - 1:Insert, 2:Preorder, 3:Inorder, 4:Postorder, 5:Exit
        Enter your choice : 1
        Enter element to insert : 20
        Enter the direction to insert (say 'l' or 'r') : rr
        
        MENU - 1:Insert, 2:Preorder, 3:Inorder, 4:Postorder, 5:Exit
        Enter your choice : 1
        Enter element to insert : 25
        Enter the direction to insert (say 'l' or 'r') : rrr
        
        MENU - 1:Insert, 2:Preorder, 3:Inorder, 4:Postorder, 5:Exit
        Enter your choice : 2
        
        Preorder : 10   5       3       2       6       15      12      20      25
        MENU - 1:Insert, 2:Preorder, 3:Inorder, 4:Postorder, 5:Exit
        Enter your choice : 3
        
        Inorder : 2     3       5       6       10      12      15      20      25
        MENU - 1:Insert, 2:Preorder, 3:Inorder, 4:Postorder, 5:Exit
        Enter your choice : 4
        
        Postorder : 2   3       6       5       12      25      20      15      10
        MENU - 1:Insert, 2:Preorder, 3:Inorder, 4:Postorder, 5:Exit
        Enter your choice : 5
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define pf printf
#define sf scanf

struct bt
{
    int info;
    struct bt *ll, *rl;
};
typedef struct bt *NODE;

void preorder(NODE root)
{
    if (root != NULL)
    {
        pf("%d\t", root->info);
        preorder(root->ll);
        preorder(root->rl);
    }
}

void inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->ll);
        pf("%d\t", root->info);
        inorder(root->rl);
    }
}

void postorder(NODE root)
{
    if (root != NULL)
    {
        postorder(root->ll);
        postorder(root->rl);
        pf("%d\t", root->info);
    }
}

NODE getnode()
{
    NODE x = (NODE)malloc(sizeof(struct bt));
    if (x == NULL)
    {
        pf("Malloc Failed!\n");
        exit(1);
    }
    return x;
}

NODE insertbt(int item, NODE root)
{
    NODE temp, cur, prev;
    char dir[15];
    int i;
    cur = root;
    temp = getnode();
    temp->info = item;
    temp->ll = temp->rl = NULL;
    if (root == NULL)
    {
        return temp;
    }
    pf("Enter the direction to insert (say 'l' or 'r') : ");
    sf("%s", dir);
    prev = NULL;
    for (i = 0 ; ( ( i < strlen(dir) ) && ( cur != NULL ) ) ; i++)
    {
        prev = cur;
        if (dir[i] == 'l')
        {
            cur = cur->ll;
        }
        else
        {
            cur = cur->rl;
        }
    }
    if ( ( cur != NULL ) || ( i != strlen(dir) ) )
    {
        pf("Cannot Insert!\n");
        free(temp);
        return root;
    }
    if (dir[i-1] == 'l')
    {
        prev->ll = temp;
    }
    else
    {
        prev->rl = temp;
    }
    return root;
}

int main()
{
    NODE root = NULL;
    int choice, item;
    for ( ; ; )
    {
        pf("\nMENU - 1:Insert, 2:Preorder, 3:Inorder, 4:Postorder, 5:Exit\n");
        pf("Enter your choice : ");
        sf("%d", &choice);
        switch (choice)
        {
            case 1 :
                pf("Enter element to insert : ");
                sf("%d", &item);
                root = insertbt(item, root);
                break;

            case 2 :
                pf("\nPreorder : ");
                preorder(root);
                break;

            case 3 :
                pf("\nInorder : ");
                inorder(root);
                break;

            case 4 :
                pf("\nPostorder : ");
                postorder(root);
                break;

            case 5 :
                exit(0);
                break;

            default:
                exit(0);
                break;
        }
    }
    return 0;
}