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
class queuell{
    public:
    Node* front , *back;
    int size;
    queuell(){
        front=nullptr;
        back=nullptr;
        size=0;
    }
    void push(int x){
        Node* temp= new Node(x);
        if(size==0){
            front=back=temp;
        }
        else{
            back->next=temp;
            back=temp;
        }
        size++;
    }
    int pop(){
        if(front==NULL) return -1;
        int ele=front->val;
        Node *temp=front;
        front=front->next;
        delete temp;
        size--;
        if(size==0) back=NULL;
        return ele;
    }
    int peek(){
        if(front==NULL) return -1;
        return front->val;
    }
    bool isEmpty(){
        return (size==0);
    }
    void print(){
        Node* temp=front;
        while(temp){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main() {
    queuell q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.print();
    cout<<q.pop()<<" "<<q.peek()<<endl;
    q.push(8);
    q.print();
    return 0;
}
