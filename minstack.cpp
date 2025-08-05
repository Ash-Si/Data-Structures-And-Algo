#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node* next;
    pair<int,int> val;
    Node(int d){
        next=nullptr;
        val.first=d;
        val.second=INT_MAX;
    }
};
class stackll{
    public:
    Node *top;
    int size;
    stackll(){
        top=nullptr;
        size=0;
    }
    void push(int x){
        Node* temp= new Node(x);
        if(top==NULL)
            temp->val.second=x;
        else
            temp->val.second=min(temp->val.first,top->val.second);
        temp->next=top;
        top=temp;
        size++;
    }
    int pop(){
        if(top==NULL) return -1;
        int ele = top->val.first;
        Node* temp= top;
        top=top->next;
        delete temp;
        size--;
        return ele;
    }
    int topval(){
        if(top==NULL) return -1;
        return top->val.first;
    }
    int getMin(){
        if(top==NULL) return -1;
        return top->val.second;
    }
    void print(){
        Node* temp=top;
        while(temp){
            cout<<temp->val.first<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main() {
    stackll s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.print();
    cout<<s.pop()<<" "<<s.pop();
    cout<<s.topval()<<" "<<s.getMin();
    return 0;
}