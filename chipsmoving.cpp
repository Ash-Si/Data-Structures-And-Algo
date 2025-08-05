#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int solve(vector<int> &ans)
{
    int even=0,odd=0;
    for(int chip:ans){
        if(chip%2==0)
            even++;
        else
            odd++;
    }
    return min(even,odd);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//#ifndef ONLINE_JUDGE
   // freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
//#endif

    ll test=1;
    //cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        vector<int> ans;
        for(int i=0;i<n;i++){
            int k; cin>>k;
            ans.push_back(k);
        }
        cout<<solve(ans);
    }
    return 0;
}
