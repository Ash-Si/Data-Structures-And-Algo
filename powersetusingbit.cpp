#include<bits/stdc++.h>
using namespace std;
void create(vector<int> &ans,vector<vector<int>> &res, int i){
    for(auto i=0;i<(1<<ans.size());i++){
        vector<int> temp;
        for(int j=0;j<ans.size();j++){
            if(i & (1<<j))
                temp.push_back(ans[j]);
        }
        res.push_back(temp);
    }
}
int main(){
    vector<int> ans={1,2,3};
    vector<vector<int>> res;
    create(ans,res,0);
    for(auto i:res){
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}