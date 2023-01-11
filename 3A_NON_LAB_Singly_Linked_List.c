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
        Enter Name : abc
        Enter ID : 1
        Enter Sem : 1
        Enter 1:Add at Front, 2:Add at Rear, 3:Add at Position, 4:Delete, 5:Search, 6:Display, 7:Exit
        Enter your choice : 2
        Enter Name : def
        Enter ID : 2
        Enter Sem : 1
        Enter 1:Add at Front, 2:Add at Rear, 3:Add at Position, 4:Delete, 5:Search, 6:Display, 7:Exit
        Enter your choice : 3
        Enter Name : ghi
        Enter ID : 3
        Enter Sem : 2
        Enter Position to Insert : 2
        Enter 1:Add at Front, 2:Add at Rear, 3:Add at Position, 4:Delete, 5:Search, 6:Display, 7:Exit
        Enter your choice : 6
        Student Name    ID    Sem
        -------------------------
         abc	   1	   1
         ghi	   3	   2
         def	   2	   1
        Enter 1:Add at Front, 2:Add at Rear, 3:Add at Position, 4:Delete, 5:Search, 6:Display, 7:Exit
        Enter your choice : 5
        Enter ID to Search : 2
        Student found with the following information :
        Name : def
        ID : 2
        Sem : 1
        Enter 1:Add at Front, 2:Add at Rear, 3:Add at Position, 4:Delete, 5:Search, 6:Display, 7:Exit
        Enter your choice : 5
        Enter ID to Search : 4
        Student ID = 4, not found. Item update
        Enter information of the student to add at end.
        Name : jkl
        ID : 4
        Sem : 2
        Enter 1:Add at Front, 2:Add at Rear, 3:Add at Position, 4:Delete, 5:Search, 6:Display, 7:Exit
        Enter your choice : 6
        Student Name    ID    Sem
        -------------------------
         abc	   1	   1
         ghi	   3	   2
         def	   2	   1
         jkl	   4	   2
        Enter 1:Add at Front, 2:Add at Rear, 3:Add at Position, 4:Delete, 5:Search, 6:Display, 7:Exit
        Enter your choice : 4
        Enter ID to Delete : 4
        Enter 1:Add at Front, 2:Add at Rear, 3:Add at Position, 4:Delete, 5:Search, 6:Display, 7:Exit
        Enter your choice : 6
        Student Name    ID    Sem
        -------------------------
         abc	   1	   1
         ghi	   3	   2
         def	   2	   1
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
    int sem;
    char name[20];
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

STUD addAtFront(char name[20], int id, int sem, STUD first)
{
    STUD temp = getnode();
    strcpy(temp->name, name);
    temp->id = id;
    temp->sem = sem;
    temp->link = first;
    return temp;
}

STUD addAtRear(char name[20], int id, int sem, STUD first)
{
    STUD current, temp = getnode();
    strcpy(temp->name, name);
    temp->id = id;
    temp->sem = sem;
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

STUD addAtPosition(char name[20], int id, int sem, int position, STUD first)
{
    int count;
    STUD previous, current, temp = getnode();
    strcpy(temp->name, name);
    temp->id = id;
    temp->sem = sem;
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
    int sem;
    char name[20];
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
        pf("Name : ");
        sf(" %[^\n]", name);
        pf("ID : ");
        sf("%d", &id);
        pf("Sem : ");
        sf("%d", &sem);
        STUD temp = getnode();
        strcpy(temp->name, name);
        temp->id = id;
        temp->sem = sem;
        temp->link = NULL;
        current->link = temp;
        return first;
    }
    pf("Student found with the following information : \n");
    pf("Name : %s\n", current->name);
    pf("ID : %d\n", current->id);
    pf("Sem : %d\n", current->sem);
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
    pf("Student Name    ID    Sem\n");
    pf("-------------------------\n");
    for ( temp = first ; temp != NULL ; temp = temp->link)
    {
        pf(" %s\t%4d\t%4d\n", temp->name, temp->id, temp->sem);
    }
}

int main()
{
    STUD first = NULL;
    int choice, id, sem, position;
    char name[20];
    for( ; ; )
    {
        pf("Enter 1:Add at Front, 2:Add at Rear, 3:Add at Position, 4:Delete, 5:Search, 6:Display, 7:Exit\n");
        pf("Enter your choice : ");
        sf("%d", &choice);
        if ( choice == 1 || choice == 2 || choice == 3 )
        {
            pf("Enter Name : ");
            scanf(" %[^\n]", name);
            pf("Enter ID : ");
            sf("%d", &id);
            pf("Enter Sem : ");
            sf("%d", &sem);
        }
        switch (choice)
        {
            case 1 :
                    first = addAtFront(name, id, sem, first);
                    break;
            
            case 2 :
                    first = addAtRear(name, id, sem, first);
                    break;

            case 3 :
                    pf("Enter Position to Insert : ");
                    sf("%d", &position);
                    first = addAtPosition(name, id, sem, position, first);
                    break;

            case 4 :
                    pf("Enter ID to Delete : ");
                    sf("%d", &id);
                    first = deleteStudent(id, first);
                    break;

            case 5 :
                    pf("Enter ID to Search : ");
                    sf("%d", &id);
                    first = search(id, first);
                    break;

            case 6 :
                    display(first);
                    break;

            case 7 :
                    pf("TERMINATING.\n");
                    exit(0);
                    break;

            default:
                    break;
        }
    }
    return 0;
}