#include<bits/stdc++.h>
using namespace std;

int BS(vector<int> arr,int low, int high,int target){
    int mid=(low+high)/2;
    if(low>high)
    return -1;
    if(target>arr[mid])
        return BS(arr,mid+1,high,target);
    else if(target<arr[mid])
        return BS(arr,low,mid-1,target);
    else
        return mid;
}

int main(){
    vector<int> arr;
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    cout<<BS(arr,0,arr.size()-1,7);
    return 0;
}