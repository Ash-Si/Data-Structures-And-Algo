#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool checkpos(vector<int> a, vector<int> b) {
    int n = a.size();
    int m = b.size();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] >= b[j]) {
            j++;
        }
        i++;
    }
    return j == m;
}

bool can_insert_to_collect(int n, int m, vector<int> a, vector<int> b, int value) {
    for (int i = 0; i <= n; ++i) {
        vector<int> temp = a;
        temp.insert(temp.begin() + i, value);
        if (checkpos(temp, b)) {
            return true;
        }
    }
    return false;
}

int solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    if (checkpos(a, b)) {
        return 0;
    }

    int low = 1, high = mod;
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (can_insert_to_collect(n, m, a, b, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll test = 1;
    cin >> test;
    while (test--) {
        cout << solve() << endl;
    }
    return 0;
}