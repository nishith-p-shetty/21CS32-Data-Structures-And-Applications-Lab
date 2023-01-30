/*
    QUESTION :
        Design, Develop and implement a program in C for the following operations on Graph (G) of cities
            a. Create a Graph of N cities using Adjacency Matrix.
            b. Print all the nodes reachable from a given starting node in a diagraph using DFS/BFS method.

    OUTPUT :
        
*/
#include <stdio.h>
#include <stdlib.h>

#define pf printf
#define sf scanf

void dfs(int n, int a[10][10], int u, int t[10][10], int s[])
{
    int v;
    static int k = 0;
    s[u] = 1;
    for (v = 0 ; v < n ; v++)
    {
        if ( a[u][v] == 1 && s[v] == 0)
        {
            t[k][0] = u;
            t[k][1] = v;
            k++;
            dfs(n, a, v, t, s);
        }
    }
}

int main()
{
    int n, i, j, u, source, a[10][10], s[10], t[10][10];
    pf("Enter the number of nodes : ");
    sf("%d", &n);
    pf("Enter the Adjacency Matrix :\n");
    for (i = 0 ; i < n ; i++)
    {
        for (j = 0 ; j < n ; j++)
        {
            sf("%d", &a[i][j]);
        }
    }
    pf("The Adjacency Matrix is :\n");
    for (i = 0 ; i < n ; i++)
    {
        for (j = 0 ; j < n ; j++)
        {
            pf("%d ", a[i][j]);
        }
        pf("\n");
    }
    pf("Enter the source vertex : ");
    sf("%d", &source);
    for (i = 0 ; i < n ; i++)
    {
        s[i] = 0;
    }
    dfs(n, a, u, t, s);
    for (i = 0 ; i < n ; i++)
    {
        if (s[i] == 1)
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