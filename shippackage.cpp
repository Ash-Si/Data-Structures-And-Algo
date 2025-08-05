#include <bits/stdc++.h>
using namespace std;
bool possible(vector<int> &weights, int days, int mid)
{
    int cnt = 1;
    int sum = 0;
    int n = weights.size();
    for (int i = 0; i < n; i++)
    {
        sum += weights[i];
        if (sum > mid)
        {
            cnt++;
            sum = weights[i];
        }
    }
    return cnt <= days;
}
int shipWithinDays(vector<int> &weights, int days)
{
    int low = INT_MIN, high = 0;
    int ans = 0;
    for (int i : weights)
    {
        low = max(low, i);
        high += i;
    }
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (possible(weights, days, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << shipWithinDays(nums, 5);
    return 0;
}