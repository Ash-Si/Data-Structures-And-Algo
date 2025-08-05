#include<bits/stdc++.h>
using namespace std;

int Printsumsub(int ind,vector<int> arr,int sum,int s){
    if(ind==arr.size()){
        if(sum==s)
            return 1;
        return 0;
    }
    if(s>sum)
    return 0;
    s+=arr[ind];
    int l=Printsumsub(ind+1,arr,sum,s);
    s-=arr[ind];
    int r=Printsumsub(ind+1,arr,sum,s);
    return l+r;
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
    cout<<Printsumsub(0,arr,2,0);
    return 0;
}