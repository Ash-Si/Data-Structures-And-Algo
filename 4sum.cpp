#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> foursum(vector<int> arr,int target){
    set<vector<int>> uniset;
    int n=arr.size();
    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            set<int> intermediate;
            for(int k=j+1;k<n;k++){
            int needed= target-(arr[i]+arr[j]+arr[k]);
            if(intermediate.find(needed) != intermediate.end()){
                vector<int> temp={arr[i],arr[j],needed,arr[k]};
                sort(temp.begin(),temp.end());
                uniset.insert(temp);
            }
            intermediate.insert(arr[k]);
        }
    }
    }
    vector<vector<int>> ans(uniset.begin(),uniset.end());

    return ans;
}

vector<vector<int>> threesum(vector<int> &arr, int target) { 
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());  
    int n = arr.size();
    
    for (int i = 0; i < n - 3; i++) {  
        if (i > 0 && arr[i] == arr[i - 1]) continue; 
        
        for (int j = i + 1; j < n - 2; j++) {  
            if (j != i + 1 && arr[j] == arr[j - 1]) continue;  
            
            int left = j + 1;  
            int right = n - 1; 
            
            while (left < right) {
                long long sum = arr[i] + arr[j] + arr[left] + arr[right];  
                
                if (sum < target) {
                    left++;  
                } 
                else if (sum > target) {
                    right--; 
                } 
                else {
                    ans.push_back({arr[i], arr[j], arr[left], arr[right]});  
                    
                    
                    while (left < right && arr[left] == arr[left + 1]) left++;
                  
                    while (left < right && arr[right] == arr[right - 1]) right--;
                    
                    left++;  
                    right--; 
                }
            }
        }
    }
    
    return ans;
}

int main(){
    vector<int> arr;
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    vector<vector<int>> ans=threesum(arr,8);
    for(auto i: ans){
        for(auto j: i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}