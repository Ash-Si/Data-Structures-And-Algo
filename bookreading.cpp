#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll solve(ll n, ll m)
{
    ll k=n/m;
    ll sum10=0;
    vector<int> temp(11,0);
    int digit=m%10;
    for(auto i=1;i<=10;i++){
        temp[i]=(i*digit)%10;
        sum10+=temp[i];
    }
    ll fullcycle = k/10;
    ll remainder = k%10;
    ll sum = fullcycle * sum10;
    for(int i=1; i<=remainder; i++)
        sum+=temp[i];
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
//#endif

    ll test=1;
    cin>>test;
    while(test--)
    {
        ll n; cin>>n;
        ll m; cin>>m;
        cout<<solve(n,m)<<endl;
    }
    return 0;
}
