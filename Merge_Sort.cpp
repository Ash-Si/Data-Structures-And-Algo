#include <bits/stdc++.h>
using namespace std;
void Merge(vector<int> &arr, int low, int mid, int high){
    int left=low;
    int right=mid+1;
    vector<int> temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

void MergeSort(vector<int> &arr,int low,int high){
    if(low>=high){
        return;
    }    
    int mid=(low+high)/2;
    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);
    Merge(arr,low,mid,high);
   
}
int main()
{
        vector<int> nums={0,2,-1,12,9,5};
        MergeSort(nums,0,nums.size()-1);
        for(auto it:nums)
        cout<<it;
        return 0;
}