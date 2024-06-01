#include <bits/stdc++.h>
using namespace std;

#define V 7
#define n 400

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


struct aQueue
{
    int arr[n];
    int front;
    int back;

    void push(int x)
    {
        if (back == n - 1)
        {
            return;
        }
        back++;
        arr[back] = x;
        if (front == -1)
        {
            front++;
        }
    }

    void pop() {
        if (front==-1 || front>back)
        {
            return;
        }
        front++;
    }

    int peek() {
        if (front==-1 || front>back)
        {
            return -1;
        }
        return arr[front];
    }

    bool empty() {
        if (front==-1 || front>back)
        {
            return true;
        }
        return false;
    }
};


void BFS(int arr[][V], int visited[], int i)
{
    aQueue q;
    q.front = 0;
    q.back = 0;
    

    cout << i << " ";
    visited[i] = 1;
    q.push(i);

    while (!q.empty())
    {
        int node = q.peek();
        q.pop();

        for (int j = 0; j < V; j++)
        {
            if (visited[j] == 0 && arr[node][j] == 1)
            {
                cout << j << " ";
                visited[j] = 1;
                q.push(j);
            }
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

    // int adjMatrix[V][V] = {
    //     {0, 1, 1, 1, 0, 0, 0},
    //     {1, 0, 1, 0, 0, 0, 0},
    //     {1, 1, 0, 1, 1, 0, 0},
    //     {1, 0, 1, 0, 1, 0, 0},
    //     {0, 0, 1, 1, 0, 1, 1},
    //     {0, 0, 0, 0, 1, 0, 0},
    //     {0, 0, 0, 0, 1, 0, 0}};

    BFS(adjMatrix, visited, 0);

    return 0;
}