#include <bits/stdc++.h>
using namespace std;
int Merge(vector<int> &arr, int low, int mid, int high){
    int left=low;
    int right=mid+1;
    vector<int> temp;
    int cnt=0;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            cnt+=mid-left+1;
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
    return cnt;
}

int MergeSort(vector<int> &arr,int low,int high){
    int cnt=0;    
    if(low>=high){
        return cnt;
    }
    int mid=(low+high)/2;
    cnt+=MergeSort(arr,low,mid);
    cnt+=MergeSort(arr,mid+1,high);
    cnt+=Merge(arr,low,mid,high);
    return cnt;
}
int main()
{
        vector<int> nums={2,4,1,3,5};
        cout<<MergeSort(nums,0,nums.size()-1);
        return 0;
}