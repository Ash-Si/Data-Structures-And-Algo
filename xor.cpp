#include <bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;  
    }
    return result;
}
int main()
{
        vector<int> nums={0,0,2,2,9,5,5};
        cout<<singleNumber(nums);
        return 0;
}