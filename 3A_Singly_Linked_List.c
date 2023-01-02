/*
    QUESTION :
        Singly Linked List (SLL) of Integer Data
            a. Create a SLL stack of N integer.
            b. Display of SLL
            c. Linear search. Create a SLL queue of N Students Data Concatenation of two SLL of
            integers.

    OUTPUT :
        Enter 1:Add at Front, 2:Add at Rear, 3:Add at Position, 4:Delete, 5:Search, 6:Display, 7:Exit
        Enter your choice : 1
        Enter ID : 1
        Enter 1:Add at Front, 2:Add at Rear, 3:Add at Position, 4:Delete, 5:Search, 6:Display, 7:Exit
        Enter your choice : 2
        Enter ID : 2
        Enter 1:Add at Front, 2:Add at Rear, 3:Add at Position, 4:Delete, 5:Search, 6:Display, 7:Exit
        Enter your choice : 3
        Enter ID : 3
        Enter Position to Insert : 2
        Enter 1:Add at Front, 2:Add at Rear, 3:Add at Position, 4:Delete, 5:Search, 6:Display, 7:Exit
        Enter your choice : 6
        Student ID
        ----------
            1
            3
            2
        Enter 1:Add at Front, 2:Add at Rear, 3:Add at Position, 4:Delete, 5:Search, 6:Display, 7:Exit
        Enter your choice : 5
        Enter ID to Search : 2
        Student found with the following information :
        ID : 2
        Enter 1:Add at Front, 2:Add at Rear, 3:Add at Position, 4:Delete, 5:Search, 6:Display, 7:Exit
        Enter your choice : 5
        Enter ID to Search : 4
        Student ID = 4, not found. Item update
        Enter information of the student to add at end.
        ID : 4
        Enter 1:Add at Front, 2:Add at Rear, 3:Add at Position, 4:Delete, 5:Search, 6:Display, 7:Exit
        Enter your choice : 6
        Student ID
        ----------
            1
            3
            2
            4
        Enter 1:Add at Front, 2:Add at Rear, 3:Add at Position, 4:Delete, 5:Search, 6:Display, 7:Exit
        Enter your choice : 4
        Enter ID to Delete : 2
        Enter 1:Add at Front, 2:Add at Rear, 3:Add at Position, 4:Delete, 5:Search, 6:Display, 7:Exit
        Enter your choice : 6
        Student ID
        ----------
            1
            3
            4
        Enter 1:Add at Front, 2:Add at Rear, 3:Add at Position, 4:Delete, 5:Search, 6:Display, 7:Exit
        Enter your choice : 7
        TERMINATING.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define pf printf
#define sf scanf

struct student
{
    int id;
    struct student *link;
};
typedef struct student *STUD;

STUD getnode()
{
    STUD x = (STUD)malloc(sizeof(struct student));
    if ( x == NULL)
    {
        pf("Malloc Failed!\n");
        exit(1);
    }
    return x;
}

STUD addAtFront(int id, STUD first)
{
    STUD temp = getnode();
    temp->id = id;
    temp->link = first;
    return temp;
}

STUD addAtRear(int id, STUD first)
{
    STUD current, temp = getnode();
    temp->id = id;
    temp->link = NULL;
    if(first == NULL)
    {
        return temp;
    }
    current = first;
    while (current->link != NULL)
    {
        current = current->link;
    }
    current->link = temp;
    return first;
}

STUD addAtPosition(int id, int position, STUD first)
{
    int count;
    STUD previous, current, temp = getnode();
    temp->id = id;
    temp->link = NULL;
    if(first == NULL && position == 1)
    {
        return temp;
    }
    if(first == NULL)
    {
        pf("Invalid Postion!\n");
        return first;
    }
    if (position == 1)
    {
        temp->link = first;
        return temp;
    }
    count = 1;
    previous = NULL;
    current = first;
    while (current->link != NULL && count != position)
    {
        previous = current;
        current = current->link;
        count++;
    }
    if (count == position)
    {
        previous->link = temp;
        temp->link = current;
        return first;
    }
    pf("Invalid Position!\n");
    return first;
}

STUD deleteStudent(int id, STUD first)
{
    STUD previous, current;
    if (first == NULL)
    {
        pf("No students in the list.\n");
        return NULL;
    }
    previous = NULL;
    current = first;
    while (current != NULL && id != current->id)
    {
        previous = current;
        current = current->link;
    }
    if ( current == NULL )
    {
        pf("Student ID not found.\n");
        return first;
    }
    if (previous == NULL)
    {
        first = first->link;
    }
    else
    {
        previous->link = current->link;
    }
    free(current);
    return first;
}

STUD search(int id, STUD first)
{
    STUD current;
    if ( first == NULL)
    {
        pf("No students in the list.\n");
        return NULL;
    }
    current = first;
    while (current->link != NULL)
    {
        if ( id == current->id )
        {
            break;
        }
        current = current->link;
    }
    if ( current->link == NULL && current->id != id)
    {
        pf("Student ID = %d, not found. Item update\n", id);
        pf("Enter information of the student to add at end.\n");
        pf("ID : ");
        sf("%d", &id);
        STUD temp = getnode();
        temp->id = id;
        temp->link = NULL;
        current->link = temp;
        return first;
    }
    pf("Student found with the following information : \n");
    pf("ID : %d\n", current->id);
    return first;
}

void display(STUD first)
{
    STUD temp;
    if ( first == NULL)
    {
        pf("No students in the list.\n");
        return ;
    }
    pf("Student ID\n");
    pf("----------\n");
    for ( temp = first ; temp != NULL ; temp = temp->link)
    {
        pf(" %4d\n", temp->id);
    }
}

int main()
{
    STUD first = NULL;
    int choice, id, position;
    for( ; ; )
    {
        pf("Enter 1:Add at Front, 2:Add at Rear, 3:Add at Position, 4:Delete, 5:Search, 6:Display, 7:Exit\n");
        pf("Enter your choice : ");
        sf("%d", &choice);
        if ( choice == 1 || choice == 2 || choice == 3 )
        {
            pf("Enter ID : ");
            sf("%d", &id);
            switch (choice)
            {
                case 1 :
                        first = addAtFront(id, first);
                        break;
                
                case 2 :
                        first = addAtRear(id, first);
                        break;

                case 3 :
                        pf("Enter Position to Insert : ");
                        sf("%d", &position);
                        first = addAtPosition(id, position, first);
                        break;

                default:
                        break;
            }
        }
        if ( choice == 4)
        {
            pf("Enter ID to Delete : ");
            sf("%d", &id);
            first = deleteStudent(id, first);
        }
        if ( choice == 5)
        {
            pf("Enter ID to Search : ");
            sf("%d", &id);
            first = search(id, first);
        }
        if ( choice == 6)
        {
            display(first);
        }
        if ( choice == 7)
        {
            pf("TERMINATING.\n");
            exit(0);
        }
    }
    return 0;
}