#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
class stackarray{
    public:
    int top=-1;
    int stack[10];
    void stackpush(int val){
        if(top==10) 
            return;
            top++;
            stack[top]=val;
    }
    void print(){
        while(top>=0)
            cout<<stack[top--]<<" ";
    }
    int gettop(){
        if(top==-1)
            return 0;
        return stack[top];
    }
    void pop(){
        if(top==-1)
            return;
        stack[top]=0;
        top--;
    }
    int getsize(){
        return top+1;
    }
};
int main() {
    stackarray s;
    int n;
    for(int i=0;i<4;i++){
        cin>>n;
        s.stackpush(n);
    }
    s.print();
    return 0;
}
