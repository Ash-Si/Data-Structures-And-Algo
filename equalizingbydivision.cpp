#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve(vector<int> &nums,unordered_map<int,int> &mpp,int k){
    int count;
    for(auto a:nums)
        mpp[a/2]++;
    for(auto i:mpp)
        count=max(count,i.second);
    if(count-k==0) cout<<0;
    else{
        
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
//#endif

    ll test=1;
//cin>>test;
    while(test--)
    {
        int n,k;
        cin>>n>>k;
        if(k==1) return 0;
        vector<int> nums(n);
        for(int i=0;i<n;i++)
            cin>>nums[i];
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mpp;
        solve(nums,mpp,k);
    }
    return 0;
}
