#include <bits/stdc++.h>
using namespace std;
void selectionsort(vector<int> &arr,int i){
    if(i>=arr.size()){
        for(auto j: arr)
            cout<<j;
        return;
    }
    int add = i;  
    for (int k = i + 1; k < arr.size(); k++) {
        if (arr[k] < arr[add]) {
            add = k;  
        }
    }
    swap(arr[i],arr[add]);
    selectionsort(arr,i+1);    
}
int main()
{
        vector<int> nums={6,7,1,0,13,-1};
        selectionsort(nums,0);
        return 0;
}