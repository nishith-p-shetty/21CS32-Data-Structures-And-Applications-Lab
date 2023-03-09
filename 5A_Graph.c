/*
    QUESTION :
        Design, Develop and implement a program in C for the following operations on Graph (G) of cities
            a. Create a Graph of N cities using Adjacency Matrix.
            b. Print all the nodes reachable from a given starting node in a diagraph using DFS/BFS method.

    OUTPUT :
        Enter the number of nodes : 7
        Enter the Adjacency Matrix :
        0 1 1 0 0 0 0 
        0 0 0 1 0 0 0 
        0 0 0 0 1 0 0 
        0 0 0 0 0 1 0 
        0 0 0 0 0 1 0 
        0 0 0 0 0 0 0 
        0 0 0 0 1 1 0
        The Adjacency Matrix is :
        0 1 1 0 0 0 0 
        0 0 0 1 0 0 0 
        0 0 0 0 1 0 0 
        0 0 0 0 0 1 0 
        0 0 0 0 0 1 0 
        0 0 0 0 0 0 0 
        0 0 0 0 1 1 0 
        Enter the source vertex : 6
        0 is not reachable
        1 is not reachable
        2 is not reachable
        3 is not reachable
        4 is reachable
        5 is reachable
        6 is reachable
*/
#include <stdio.h>
#include <stdlib.h>

#define pf printf
#define sf scanf

void dfs(int n, int adj_mx[10][10], int source, int temp[10][10], int visited[])
{
    int i;
    static int k = 0;
    visited[source] = 1;
    for (i = 0 ; i < n ; i++)
    {
        if ( adj_mx[source][i] == 1 && visited[i] == 0)
        {
            temp[k][0] = source;
            temp[k][1] = i;
            k++;
            dfs(n, adj_mx, i, temp, visited);
        }
    }
}

int main()
{
    int n, i, j, source, adj_mx[10][10], visited[10], temp[10][10];
    pf("Enter the number of nodes : ");
    sf("%d", &n);
    pf("Enter the Adjacency Matrix :\n");
    for (i = 0 ; i < n ; i++)
    {
        for (j = 0 ; j < n ; j++)
        {
            sf("%d", &adj_mx[i][j]);
        }
    }
    pf("The Adjacency Matrix is :\n");
    for (i = 0 ; i < n ; i++)
    {
        for (j = 0 ; j < n ; j++)
        {
            pf("%d ", adj_mx[i][j]);
        }
        pf("\n");
    }
    pf("Enter the source vertex : ");
    sf("%d", &source);
    for (i = 0 ; i < n ; i++)
    {
        visited[i] = 0;
    }
    dfs(n, adj_mx, source, temp, visited);
    for (i = 0 ; i < n ; i++)
    {
        if (visited[i] == 1)
        {
            pf("%d is reachable\n", i);
        }
        else
        {
            pf("%d is not reachable\n", i);
        }
    }
    return 0;
}