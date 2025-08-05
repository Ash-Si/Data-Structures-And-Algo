#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int solve(int n, int k, vector<int> a, vector<int> b){
    int maxele=-1;
    int maxsum=0;
    bool allneg=false;
    for(int i=0;i<n;i++)
        maxele=max(a[i],maxele);
    for(int i=0;i<n;i++){
        if(b[i]!=-1){
            int sum=a[i]+b[i];
            if(sum<maxele)
                return 0;
            maxsum=max(maxsum,b[i]+a[i]);
            allneg=true;
        }
    }
    if(maxele=maxsum) return 1;
    if(allneg) return (k-maxele)+2;
    else return k-maxsum;
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
        int n,k; cin>>n>>k;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        cout<<solve(n,k,a,b)<<endl;
    }
    return 0;
}
