#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int solve(vector<int> &prices)
{
    int count = 0;
    int i = prices.size() - 2;
    int mini = prices.back();
    while (i >= 0)
    {
        if (prices[i] > mini)
            count++;
        else
            mini = min(mini, prices[i]);
        i--;
    }
    return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    // #endif
        ll test = 1;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        vector<int> prices(n);
        for (int i = 0; i < n; i++)
        {
            cin >> prices[i];
        }
        cout << solve(prices) << endl;
    }
    return 0;
}