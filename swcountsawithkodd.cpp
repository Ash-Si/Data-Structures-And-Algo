#include <bits/stdc++.h>
using namespace std;

int numberOfSubarrays(vector<int> &nums, int k)
{
    int left = 0, right = 0, n = nums.size();
    int count = 0, oddcount = 0, lastodd = 0;
    while (right < n)
    {
        if ((nums[right] & 1) == 1)
            oddcount++;
        if (oddcount == k)
        {
            lastodd = 0;
            while (oddcount == k)
            {
                if ((nums[left] & 1) == 1)
                    oddcount--;
                lastodd++;
                left++;
            }
        }
        count += lastodd;
        right++;
    }
    return count;
}

int main()
{
    vector<int> nums = {1, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    //vector<int> nums = {1,1,2,1,1};
    cout << numberOfSubarrays(nums, 2);
    return 0;
}
