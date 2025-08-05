#include <bits/stdc++.h>
using namespace std;
bool possible(vector<int>& bloomDay, int m, int k, int mid){
    int cnt=0;
    int noofb=0;
    int n=bloomDay.size();
    for(int i=0;i<n;i++){
        if(bloomDay[i]<=mid)
            cnt++;
        else{
            noofb+=(cnt/k);
            cnt=0;
        }
    }
        noofb+=(cnt/k);
        if(noofb>=m) return true;
    return false;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    if(bloomDay.size()<m*k) return -1;
    int mini=*min_element(bloomDay.begin(),bloomDay.end());
    int maxi=*max_element(bloomDay.begin(),bloomDay.end());        
    int ans=-1;
    while(mini<=maxi){
        int mid=mini+(maxi-mini)/2;
        if(possible(bloomDay,m,k,mid)==true){
            ans=mid;
            maxi=mid-1;
        }
        else 
            mini=mid+1;
    }
    return ans;
}

int main()
{
        vector<int> nums={1,10,3,10,2};
        cout<<minDays(nums,3,2);
        return 0;
}