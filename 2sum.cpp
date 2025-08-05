#include<bits/stdc++.h>
using namespace std;

vector<int> twosum(vector<int> v,int target){
    vector<pair<int,int>> v1;
    for(int i=0;i<v.size();i++){
        v1.push_back(make_pair(v[i],i));
    }
    sort(v1.begin(),v1.end());
    int left=0;
    int right=v1.size()-1;
    while(left<right){
        int sum=v1[left].first+v1[right].first;
        if(sum>target)
        right--;
        else if(sum<target)
        left++;
        else
        return {v1[left].second,v1[right].second};
    }
    return {-1,-1};
}

int main(){
    vector<int> v={2,11,7,15};
    vector<int> V=twosum(v,9);
    for(auto i:V)
    cout<<i;
    return 0;    
}