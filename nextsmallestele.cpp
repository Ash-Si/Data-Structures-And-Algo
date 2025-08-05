#include <bits/stdc++.h>
using namespace std;
vector<int> nextsmallestele(vector<int> nums){
    int n= nums.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()>=nums[i])
            st.pop();
        if (st.empty())
            ans[i]=-1;
        else
            ans[i]=st.top();
        st.push(nums[i]);
    }
    return ans;
}
int main() {
    vector<int> nums = {1, 3, 2, 4};
    vector<int> res = nextsmallestele(nums);
    for(auto i: res)
        cout<<i<<" ";
    return 0;
}
