#include<bits/stdc++.h>
using namespace std;

void perm(int ind,vector<int> &arr,vector<vector<int>> &ans){
    if(ind==arr.size()){
        ans.push_back(arr);
        return;
    }
    for(int i=ind;i<arr.size();i++){
        swap(arr[i],arr[ind]);
        perm(ind+1,arr,ans);
        swap(arr[i],arr[ind]);
    }
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
    vector<vector<int>> ans;
    perm(0,arr,ans);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}