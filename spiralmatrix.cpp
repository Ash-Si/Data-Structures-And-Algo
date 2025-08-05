#include <bits/stdc++.h>
using namespace std;

vector<int> Spiral(vector<vector<int>> &arr)
{
    int m = arr.size();
    vector<int> ans;
    int n = arr[0].size();
    int left = 0, right = n - 1;
    int top = 0, bottom = m - 1;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            ans.push_back(arr[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(arr[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(arr[bottom][i]);
            }
        }
        bottom--;
        for (int i = bottom; i >= top; i--)
        {
            ans.push_back(arr[i][left]);
        }
        left++;
    }
    return ans;
}

int main()
{
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<vector<int>> arr(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            arr[i][j] = a;
        }
    }
    vector<int> ans = Spiral(arr);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}