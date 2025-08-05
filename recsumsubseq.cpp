#include<bits/stdc++.h>
using namespace std;

bool Printsumsub(int ind, vector<int> arr,vector<int> res,int sum,int s){
    if(ind==arr.size()){
        if(sum==s){
        for(auto i:res)
            cout<<i<<" ";
            cout<<endl;
            return true;
        }
        return false;
    }
    // if(s>sum)
    // return;
    res.push_back(arr[ind]);
    s+=arr[ind];
    if(Printsumsub(ind+1,arr,res,sum,s)==true) return true;
    s-=arr[ind];
    res.pop_back();
    if(Printsumsub(ind+1,arr,res,sum,s)==true) return true;
    return false;
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
    vector<int> res;
    int s=0;
    bool ans=Printsumsub(0,arr,res,4,s);
    return 0;
}