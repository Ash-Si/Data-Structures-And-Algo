#include<bits/stdc++.h>
using namespace std;

void Printsub(int ind, vector<int> arr,vector<int> res){
    if(ind==arr.size()){
        for(auto i:res)
            cout<<i<<" ";
        if(res.size()==0)
            cout<<"{}";
        cout<<endl;
        return;
    }
    res.push_back(arr[ind]);
    Printsub(ind+1,arr,res);
    res.pop_back();
    Printsub(ind+1,arr,res);
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
    Printsub(0,arr,res);
    return 0;
}