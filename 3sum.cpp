#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threesumset(vector<int> arr){
    set<vector<int>> uniset;
    int n=arr.size();
    for(int i=0;i<n;i++){
        set<int> intermediate;
        for(int j=i+1;j<n;j++){
            int needed= -(arr[i]+arr[j]);
            if(intermediate.find(needed) != intermediate.end()){
                vector<int> temp={arr[i],arr[j],needed};
                sort(temp.begin(),temp.end());
                uniset.insert(temp);
            }
            intermediate.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(uniset.begin(),uniset.end());

    return ans;
}

vector<vector<int>> threesum(vector<int> &arr){
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        int left=i+1;
        int right=n-1;
        while(left<right){
            int sum=arr[i]+arr[left]+arr[right];
            if(sum<0) left++;
            else if(sum>0) right--;
            else{
                ans.push_back({arr[i],arr[left],arr[right]});
                while(left< right && arr[left]==arr[left+1]) left++;
                while(left< right && arr[right]==arr[right-1]) right--;
                left++;right--;
            }
        }
    }
    return ans;
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
    vector<vector<int>> ans=threesum(arr);
    for(auto i: ans){
        for(auto j: i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}