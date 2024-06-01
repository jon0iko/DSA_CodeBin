#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows=matrix.size();
    int cols=matrix[0].size();
    int l=0;
    int r=cols-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(matrix[mid/cols][mid%cols]==target)
            return true;
        else if(matrix[mid/cols][mid%cols]<target)
            l=mid+1;
        else
            r=mid-1;
    }
    return false;
}


  bool OptimizedsearchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(),
			cols = matrix[0].size(),
            row = 0, col = cols - 1;
			
        while (row < rows && col > -1) {
            int cur = matrix[row][col];
            if (cur == target) return true;
            if (target > cur) row++;
            else col--;
        }
        
        return false;
    }

int main()
{
    vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=65;

    //if i need to take input from user
    // int rows,cols;
    // cin>>rows>>cols;
    // vector<vector<int>> matrix(rows,vector<int>(cols));
    // for(int i=0;i<rows;i++)
    //     for(int j=0;j<cols;j++)
    //         cin>>matrix[i][j];
    // int target;
    // cin>>target;

    searchMatrix(matrix,target);
    if(searchMatrix(matrix,target))
        cout<<"true";
    else
        cout<<"false";
    return 0;
}