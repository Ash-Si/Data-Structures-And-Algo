#include <bits/stdc++.h>
using namespace std;
int counthr(vector<int>& piles, int mid,int h){
    int n=piles.size();
    int ans=0;
    for(int i=0;i<n;i++){
        if(piles[i]%mid==0 && piles[i]>=mid)
            ans+=(piles[i]/mid);
        else if(piles[i]<mid)
            ans+=1;
        else{
            ans+=(piles[i]/mid);
            ans+=1;
        } 
        if(ans>h) return 2; 
    }
        if(ans==h) return 1;
    return 0;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int n=piles.size();
    sort(piles.begin(),piles.end());
    int low=1;
    int high=piles[n-1];
    if(n==h)
    return high;
    while(low<=high){
        int mid=low+(high-low)/2;
        int result= counthr(piles,mid,h);
        if(result==1) return mid;
        else if(result==2)
        low=mid+1;
        else
        high=mid-1;
    }
    return -1;
}
int main()
{
        vector<int> nums={4,11,20,23,30};
        cout<<minEatingSpeed(nums,6);
        return 0;
}