#include<iostream>
#include<vector>
using namespace std;

//approach 1-merge and sort
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> merged;
    int i=0,j=0;
    while(i<nums1.size() && j<nums2.size())
    {
        if(nums1[i]<nums2[j])
            merged.push_back(nums1[i++]);
        else
            merged.push_back(nums2[j++]);
    }
    while(i<nums1.size())
        merged.push_back(nums1[i++]);
    while(j<nums2.size())
        merged.push_back(nums2[j++]);
    int n=merged.size();
    if(n%2==0)
        return (merged[n/2]+merged[n/2-1])/2.0;
    else
        return merged[n/2];
}

//approach 2- binary search
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //to ensure nums1 is smaller
    if(nums1.size()>nums2.size())
        return findMedianSortedArrays(nums2,nums1);
    int x=nums1.size();
    int y=nums2.size();
    int low=0;
    int high=x;
    while(low<=high)
    {
        //partitionX is the number of elements in the left half of nums1
        int partitionX=(low+high)/2;
        //partitionY is the number of elements in the left half of nums2
        int partitionY=(x+y+1)/2-partitionX;
        //maxX is the maximum element in the left half of nums1
        int maxX=(partitionX==0)?INT_MIN:nums1[partitionX-1];
        int maxY=(partitionY==0)?INT_MIN:nums2[partitionY-1];
        //minX is the minimum element in the right half of nums1
        int minX=(partitionX==x)?INT_MAX:nums1[partitionX];
        int minY=(partitionY==y)?INT_MAX:nums2[partitionY];
        //Check if this partition is valid by verifying if the largest number on the left side is smaller than the smallest number on the right side.
        if(maxX<=minY && maxY<=minX)
        {
            if((x+y)%2==0)
                return (max(maxX,maxY)+min(minX,minY))/2.0;
            else
                return max(maxX,maxY);
        }
        else if(maxX>minY)
            high=partitionX-1;
        else
            low=partitionX+1;
    }
    return 0.0;
}

int main()
{
    vector<int> nums1={1,3};
    vector<int> nums2={2};
    //if i need to take input from user
    // int n,m;
    // cin>>n>>m;
    // vector<int> nums1(n);
    // vector<int> nums2(m);
    // for(int i=0;i<n;i++)
    //     cin>>nums1[i];
    // for(int i=0;i<m;i++)
    //     cin>>nums2[i];
    
    cout<<findMedianSortedArrays(nums1,nums2);
    return 0;
}

