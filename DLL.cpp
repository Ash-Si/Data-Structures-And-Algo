#include<bits/stdc++.h>
using namespace std;

class DLL{
    public:
    int data;
    DLL* next;
    DLL* prev;

    DLL(int data1, DLL* next1, DLL* prev1): data(data1), next(next1), prev(prev1){}
};

void printDLL(DLL* head){
    for(auto i=head;i!=nullptr;i=i->next){
        cout<<i->data<<" ";
    }
}

DLL* removeHead(DLL* head){
    DLL* temp=head;
    temp=temp->next;
    temp->prev=nullptr;
    delete head;
    return temp;
}

DLL* removeTail(DLL* head){
    if(head==NULL) return NULL;
    if(head->next==NULL) {
        delete head;
        return NULL;
    }
    DLL* temp=head, *end=NULL;
    while(temp->next->next!=nullptr)
        temp=temp->next;
    delete temp->next;
    temp->next=NULL;
    return head;
}

DLL* removeK(DLL* head, int k){
    if(head==NULL) return NULL;
    if(head->next==NULL && k==1){
        delete head;
        return NULL;
    }
    DLL* temp=head, *end;
    if(k==1){
        head=head->next;
        head->prev=nullptr;
        delete temp;
        return head;
    }
    int count=1;
    while(temp!=NULL){
        if(count==k){
            end=temp->prev;
            end->next=temp->next;
            if(temp->next!=NULL)
                temp->next->prev=temp->prev;
            else{
                delete temp;
                return head;
            }
            delete temp;
            return head;
        }
        temp=temp->next;
        count++;
    }
    return head;
}

int main(){
    vector<int> ans={1,2,3,4,5,6};
    DLL *head= new DLL(ans[0],nullptr,nullptr);
    DLL *temp=head, *end=NULL;
    for(int i=1;i<ans.size();i++){
    end = new DLL(ans[i],nullptr,temp);
    temp->next=end;
    temp=end;
    }
    //head=removeHead(head);
    //head=removeTail(head);
    head=removeK(head,1);
    printDLL(head);
    return 0;
}