#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve(int n, int x)
{
    vector<int> P;
    for(int i=0;i<n;i++)
        P.push_back(i);
    if(x!=n)
        swap(P[x],P[n-1]);
    for(auto i:P)
        cout<<i<<" ";
    cout<<endl;
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
        int n,x; cin>>n>>x;
        if(x>n) {
            cout<<0<<endl;
            continue;
        }
        solve(n,x);
    }
    return 0;
}
