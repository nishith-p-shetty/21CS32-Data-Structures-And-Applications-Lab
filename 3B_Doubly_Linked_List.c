/*
    QUESTION :
        Design, Develop and Implement a menu driven Program in C for the following operationson
        Doubly Linked List (DLL) of Professor Data with the fields: ID, Name, Branch, Area of
        specialization
            a. Create a DLL stack of N Professor’s Data.
            b. Create a DLL queue of N Professor’s Data
        Display the status of DLL and count the number of nodes in it.
    OUTPUT :
        Enter 1:Create, 2:Insert to left of element, 3:Deleete All, 4:Display, 5:Exit
        Enter your choice : 1
        Enter item to insert DLL by inserting at front : 5
        Enter 1:Create, 2:Insert to left of element, 3:Deleete All, 4:Display, 5:Exit
        Enter your choice : 1
        Enter item to insert DLL by inserting at front : 3
        Enter 1:Create, 2:Insert to left of element, 3:Deleete All, 4:Display, 5:Exit
        Enter your choice : 4
        Contents od DLL are
        ----------
         3       5
        Enter 1:Create, 2:Insert to left of element, 3:Deleete All, 4:Display, 5:Exit
        Enter your choice : 2
        Adding to left of item : 5
        Enter the item tio be inserted to left of ritem 5 :4
        Enter 1:Create, 2:Insert to left of element, 3:Deleete All, 4:Display, 5:Exit
        Enter your choice : 4
        Contents od DLL are
        ----------
         3       4       5
        Enter 1:Create, 2:Insert to left of element, 3:Deleete All, 4:Display, 5:Exit
        Enter your choice : 3
        Enter ket to delete : 4
        Key found at 1 positions and are deleted
        Enter 1:Create, 2:Insert to left of element, 3:Deleete All, 4:Display, 5:Exit
        Enter your choice : 4
        Contents od DLL are
        ----------
         3       5
        Enter 1:Create, 2:Insert to left of element, 3:Deleete All, 4:Display, 5:Exit
        Enter your choice : 5
        TERMINATING.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define pf printf
#define sf scanf

struct node
{
    int info;
    struct node *l, *r;
};
typedef struct node *NODE;

NODE getnode()
{
    NODE x = (NODE)malloc(sizeof(struct node));
    if ( x == NULL)
    {
        pf("Malloc Failed!\n");
        exit(1);
    }
    return x;
}

NODE create(int item, NODE head)
{
    NODE current, temp = getnode();
    temp->info = item;
    current = head->r;
    head->r = temp;
    temp->l = head;
    temp->r = current;
    current->l = temp;
    return head;
}

NODE addAtLeft(int ritem, NODE head)
{
    NODE current, previous, temp = getnode();
    if(head ->r == head)
    {
        pf("List is Empty\n");
        return head;
    }
    current = head->r;
    while (current != head && ritem != current->info)
    {
        current = current->r;
    }
    if (current == head)
    {
        pf("Key not found\n");
        return head;
    }
    previous = current->l;
    temp = getnode();
    pf("Enter the item tio be inserted to left of ritem %d :", ritem);
    sf("%d", &temp->info);
    previous->r = temp;
    temp->l = previous;
    current->l = temp;
    temp->r = current;
    return head;
}

NODE deleteAll(int item, NODE head)
{
    NODE previous, current, next;
    int count = 0;
    if (head->r == head)
    {
        pf("List is empty\n");
        return head;
    }
    current = head->r;
    while (current != head)
    {
        if (item != current->info)
        {
            current = current->r;
        }
        else
        {
            count++;
            previous = current->l;
            next = current->r;
            previous->r = next;
            next->l = previous;
            free(current);
            current = next;
        }
    }
    if ( count == 0 )
    {
        pf("Key not found\n");
    }
    else
    {
        pf("Key found at %d positions and are deleted\n", count);
    }
    return head;
}

void display(NODE head)
{
    NODE temp;
    if ( head->r == head)
    {
        pf("List is empty\n");
        return;
    }
    pf("Contents od DLL are\n");
    pf("----------\n");
    for ( temp = head->r ; temp != head ; temp = temp->r)
    {
        pf(" %d\t", temp->info);
    }
    pf("\n");
}

int main()
{
    NODE head = getnode();
    int choice, item;
    head->r = head->l = head;
    for( ; ; )
    {
        pf("Enter 1:Create, 2:Insert to left of element, 3:Deleete All, 4:Display, 5:Exit\n");
        pf("Enter your choice : ");
        sf("%d", &choice);
        switch (choice)
        {
            case 1 :
                    pf("Enter item to insert DLL by inserting at front : ");
                    sf("%d", &item);
                    head = create(item, head);
                    break;
            
            case 2 :
                    pf("Adding to left of item : ");
                    sf("%d", &item);
                    head = addAtLeft(item, head);
                    break;

            case 3 :
                    pf("Enter ket to delete : ");
                    sf("%d", &item);
                    head = deleteAll(item, head);
                    break;

            case 4 :
                    display(head);
                    break;

            case 5 :
                    pf("TERMINATING.\n");
                    exit(0);
                    break;

            default:
                    break;
        }
    }
    return 0;
}