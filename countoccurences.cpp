#include<bits/stdc++.h>
using namespace std;

vector<int> count(vector<int> arr,int target){
    int lb=lower_bound(arr.begin(),arr.end(),target)-arr.begin();
    if(lb==arr.size()||arr[lb]!=target)
    return {-1,-1};
    int ub=upper_bound(arr.begin(),arr.end(),target)-arr.begin();
    return {lb,ub-1};
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
        vector<int> ans=count(arr,12);
        for(auto i:ans)
            cout<<i<<" ";
        return 0;
}