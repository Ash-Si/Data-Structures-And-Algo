#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pascalrow(int n){
        if(n==0)
        return {{}};    

        if(n==1)
        return {{1}};
        
        vector<vector<int>> prevrow=pascalrow(n-1);
        vector<int> newrow(n,1);

        for(int j=1;j<n-1;j++){
            newrow[j]=prevrow.back()[j-1]+prevrow.back()[j];
        }
        prevrow.push_back(newrow);
        return prevrow;
}

int main(){
    vector<vector<int>> ans;
    ans=pascalrow(5); 
    for(auto i: ans){
        for (auto j: i)
        cout<<j<<" ";
        cout<<endl;
    }   
    return 0;
}