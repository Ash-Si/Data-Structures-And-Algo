#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pascalrow(int arr){
    vector<vector<int>> answer;
    vector<int> row;
    int ans=1;
    for(int j=1;j<=arr;j++){
        row.push_back(1);
    for(int i=1;i<j;i++){
        ans=ans*(j-i);
        ans=ans/i;
        row.push_back(ans);
    }
    answer.push_back(row);
    row.clear();
}
    return answer;
}

int main(){
    vector<vector<int>> row=pascalrow(5);
    for(auto i:row){
        for(auto j:i)
        cout<<j<<" ";
        cout<<endl;
    }
        
    return 0;
}