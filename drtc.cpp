#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve(string s,int n){
    vector<string> ans;
    int count=0;
    for(int i=0;i<n;i++){
        string t=s;
        t[i]= t[i]=='0' ? '1' : '0';
        ans.push_back(t);
        for(int j=0;j<ans.back().size();j++){
            if(ans.back()[j]=='1')
                count++;
        }
    }    
    cout<<count<<endl;
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
        int n; cin>>n;
        string s; cin>>s;

        solve(s,n);
    }
    return 0;
}
