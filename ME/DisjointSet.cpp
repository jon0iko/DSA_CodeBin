#include <bits/stdc++.h>
using namespace std;

struct DisjointSet
{
    int *rank, *parent, n;

    DisjointSet(int n)
    {
        rank = new int[n];
        parent = new int[n];
        this->n = n;

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        else
        {
            int result = find(parent[x]);
            parent[x] = result;
            return result;
        }
    }

    void Union(int x, int y)
    {
        int xset = find(x);
        int yset = find(y);

        if (xset == yset)
            return;

        if (rank[xset] < rank[yset])
        {
            parent[xset] = yset;
        }
        else if (rank[xset] > rank[yset])
        {
            parent[yset] = xset;
        }
        else
        {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};

int main()
{

    DisjointSet set(5);
    set.Union(0, 2);
    set.Union(4, 2);
    set.Union(3, 1);

    if (set.find(4) == set.find(0))
        cout << "Yes\n";
    else
        cout << "No\n";
    if (set.find(1) == set.find(0))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}