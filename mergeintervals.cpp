#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int start=0;
    int end=1;
    sort(intervals.begin(),intervals.end());
    for(int i=0;i<intervals.size()-1;i++){
        if(intervals[i][end]>=intervals[i+1][start]){
            intervals[i+1][start]=intervals[i][start];
            intervals[i+1].back()=max(intervals[i][end],intervals[i+1][end]);
            intervals.erase(intervals.begin()+i);
            i--;
        }
    }
    return intervals;
}

int main(){
    vector<vector<int>> arr={{1,3},{2,4},{2,6},{8,9},{8,10},{9,11},{15,18},{16,17}};
    vector<vector<int>> ans=merge(arr);
    for(auto i: ans){
        for(auto j: i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}