#include <bits/stdc++.h>
using namespace std;

#define V 7

void init(int arr[][V])
{
    int i, j;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            arr[i][j] = 0;
}

void addEdge(int arr[][V], int i, int j)
{
    arr[i][j] = 1;
    arr[j][i] = 1;
}

void DFS(int arr[][V], int visited[], int i)
{
    int j;
    cout << i << " ";
    visited[i] = 1;

    for (j = 0; j < V; j++)
    {
        if (!visited[j] && arr[i][j] == 1)
        {
            DFS(arr, visited, j);
        }
    }
}

int main()
{

    int visited[V] = {0};
    int adjMatrix[V][V];

    init(adjMatrix);
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 2, 0);
    addEdge(adjMatrix, 2, 3);

    DFS(adjMatrix, visited, 0);

    return 0;
}