#include<bits/stdc++.h>
using namespace std;
int setrightbit(int n){   
int count=0;
    // while(count<32){
    //     if((n&(1<<count))==0){
    //         n=(n|(1<<count));
    //         return n;
    //     }
    //     count++;
    // }
    return (n|(n+1));
}
int main(){
    int n; 
    cin>>n;
    cout<<setrightbit(n);    
    return 0;
}