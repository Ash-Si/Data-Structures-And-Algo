#include <bits/stdc++.h>
using namespace std;

int kDistinctChar(string &s, int k){
    int left = 0, right = 0, n = s.size(), maxLen = 0;
    unordered_map<char, int> mpp;
    while (right < n){
        mpp[s[right]]++;
        if (mpp.size() > k && left < right){
            mpp[s[left]]--;
            if (mpp[s[left]] <= 0)
                mpp.erase(s[left]);
            left++;
        }
        if (mpp.size() <= k)
            maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}

int main()
{
    string s = "aababbcaacc";
    cout << kDistinctChar(s, 2);
    return 0;
}
