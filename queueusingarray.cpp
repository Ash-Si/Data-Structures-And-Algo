#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
class qarray{
    public:
    int start=-1;
    int end=-1;
    int queue[10];
    void push(int val){
        if(end>=10)
            return;
        if(start==-1)
            start++;
        end++;
        queue[end]=val;
    }
    void pop(){
        if(start==-1){
            cout<<"out of bounds";
            return;
        }
        queue[start]=0;
        start++;
        if(start==end)
            start=end=-1;
    }
    int startval(){
        if(start==-1)
            return 0;
        return queue[start];
    }
    int endval(){
        if(end==10)
            return 0;
        return queue[end];
    }
    int size(){
        if(start==-1)
            return 0;
        else 
            return end-start+1;
    }
    void print(){
        for(int i=start;i<=end;i++)
            cout<<queue[i]<<" ";
    }
};
int main() {
    qarray q;
    int n;
    for(int i=0;i<4;i++){
        cin>>n;
        q.push(n);
    }
    q.print();
    cout<<endl;
    cout<<q.size()<<" "<<q.startval()<<" "<<q.endval()<<endl;
    q.pop();
    q.pop();
    q.pop();
    q.print();
    cout<<endl<<q.startval()<<" "<<q.endval()<<endl;
    q.push(10);
    cout<<q.startval()<<" "<<q.endval()<<endl;
    return 0;
}
