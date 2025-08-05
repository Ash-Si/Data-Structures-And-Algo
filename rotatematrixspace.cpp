#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> Rotate (vector<vector<int>> arr){
    int n=arr.size();
    vector<vector<int>> rotata(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            rotata[j][n-1-i]=arr[i][j];
        }
    }  
    return rotata;
}

int main(){
    int n=0;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            arr[i][j]=a;
        }
    }
    vector<vector<int>> rotata=Rotate(arr);
    for(auto i:rotata){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}