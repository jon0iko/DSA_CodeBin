#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<int> k;
        int m = mat.size() , n = mat[0].size();
        for (int r=0; r<m; r++)        // r-> row
        {
            k.clear();
            for (int j=0,i=r; j<n && i<m ; j++,i++) k.push_back(mat[i][j]);    // add to vector
            sort(k.begin(),k.end());
            for (int j=0,i=r; j<n && i<m ; j++,i++) mat[i][j]=k[j];            // replace
        }
        for (int c=1; c<n; c++)       // c->column
        {
            k.clear();
            for (int i=0, j=c; j<n && i<m; i++, j++) k.push_back(mat[i][j]);   // add to vector
            sort(k.begin(),k.end());
            for (int i=0, j=c; j<n && i<m; i++, j++) mat[i][j] = k[i];         //replace
        }
        return mat;
    }

int main()
{
    vector<vector<int>> mat = {{3,3,1,1},{2,2,1,2},{1,1,1,2}};
    vector<vector<int>> res = diagonalSort(mat);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[0].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}