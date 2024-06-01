//need to find index(0-based) of a given key in an array (unsorted)

#include <bits/stdc++.h>
using namespace std;

int search(pair<int, int> a[], int x, int n)
{
    int st = 0;
    int ed = n - 1;

    while (st <= ed)
    {
        int mid = st + (ed - st) / 2;

        if (a[mid].first == x)
        {
            return a[mid].second;
        }
        else if (a[mid].first < x)
        {
            st = mid + 1;
        }
        else if (a[mid].first > x)
        {
            ed = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int n, m, q, flag = 0;
    cin >> n;
    pair<int, int> arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = flag;
        flag++;
    }
    sort(arr, arr + n);
    cin >> m;
    while (m--)
    {
        cin >> q;
        cout << search(arr, q, n) << endl;
    }
}