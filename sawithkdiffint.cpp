#include <bits/stdc++.h>
using namespace std;

int countsubarray(vector<int>& nums, int k) {
    int left = 0, right = 0, n = nums.size(), count = 0;
    unordered_map<int,int> mpp;
    while(right < n){
        mpp[nums[right]]++;
        while(mpp.size() > k && left < right){
            mpp[nums[left]]--;
            if(mpp[nums[left]]==0)
                mpp.erase(nums[left]);
            left++;
        }
        if(mpp.size() <= k)
            count += (right - left + 1);
        right++;
    }
    return count;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return countsubarray(nums,k) - countsubarray(nums,k-1);
}
int main() {
    vector<int> nums = {1, 1, 1, 1};
    cout<<subarraysWithKDistinct(nums,1);
    return 0;
}
