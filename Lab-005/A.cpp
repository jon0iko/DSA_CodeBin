//generrate combination of nCk where n in (input-1) in an descending order

#include <iostream>
using namespace std;
int a[1000];
int k;

void genCombii(int i, int j)
{

    if (j == k)
    {
        for (int i = 0; i < k; i++)
        {
            cout << a[i];
            if (i != k - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    if (i < 0)
        return;
    for (int k = i; k >= 0; k--)
    {
        a[j] = k;
        genCombii(k - 1, j + 1);
    }
}

int main()
{
    int n;
    cin >> n >> k;
    genCombii(n - 1, 0);
}