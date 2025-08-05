#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node* next;
    int val;
    Node(int d){
        next=nullptr;
        val=d;
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
        temp->next=top;
        top=temp;
        size++;
    }
    int pop(){
        if(top==NULL) return -1;
        int ele = top->val;
        Node* temp= top;
        top=top->next;
        delete temp;
        size--;
        return ele;
    }
    int topval(){
        if(top==NULL) return -1;
        return top->val;
    }
    int retsize(){
        return size;
    }
    void print(){
        Node* temp=top;
        while(temp){
            cout<<temp->val<<" ";
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
    cout<<s.topval()<<" "<<s.retsize();
    return 0;
}
