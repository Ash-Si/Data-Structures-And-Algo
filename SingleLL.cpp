#include<bits/stdc++.h>
using namespace std;
class LL{
    public:
    int data;
    LL* next;
    LL(int data1,LL *next1){
        data=data1;
        next=next1;
    }
    void printLL(LL* head){
        for(LL* i=head;i!=nullptr;i=i->next)
            cout<<i->data<<" ";
    }
    LL* removeHead(LL* head){
        if(head==NULL) return head;
        LL* temp= head;
        head=head->next;
        delete temp;
        return head;
    }
    LL* removetail(LL* head){
        if(head==NULL) return head;
        if(head->next==NULL){
            delete head;
            return NULL;
        }
        LL* temp;
        for(auto i=head;i!=NULL;i=i->next){
            if(i->next->next==NULL){
            temp=i; 
            break;
            }
        }
        delete temp->next;
        temp->next=nullptr;
        return head;
    }
    LL* removek(LL* head, int k){
        if(head==NULL || k<=0) return NULL;
        LL* temp=head,*prev=NULL;
        int count=1;
        if(k==1){
            head=head->next;
            delete temp;
            return head;
        }
        while(temp!=nullptr && count<=k){
            if(count==k){
                prev->next=temp->next;
                delete temp;
                return head;
            }
            prev=temp;
            temp=temp->next;
            count++;
        }
        return head;
    }
    LL* removeEl(LL* head, int k){
        if(head==NULL) return NULL;
        LL* temp=head,*prev;
        if(head->data==k){
            temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        while(temp!=nullptr){
            if(temp->data==k){
                prev->next=temp->next;
                delete temp;
                return head;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
    LL* insertHead(LL* head,int k){
        LL* temp=new LL(k,head);
        head=temp;
        return head;
    }
    LL* insertTail(LL* head, int k){
        LL* temp=new LL(k,nullptr);
        for(auto i=head;i!=nullptr;i=i->next){
            if(i->next==nullptr){
                i->next=temp;
                break;
            }
        }
        return head;
    }
    LL* insertK(LL* head, int k, int value){
        if(head==NULL)
            return new LL(value, nullptr);
        if(k==1)
            return new LL(value,head);
        int count=1;
        LL* temp= new LL(value,nullptr);
        for(auto i=head;i!=nullptr;i=i->next){
            if(count==k-1){
                temp->next=i->next;   
                i->next=temp;
                return head;
            }
            count++;
        }
        return head;
    }
};

int main(){
    vector<int> ans= {1,2,3,4,5,6};
    LL* head=new LL(1,nullptr);
    LL* temp,*end;
    temp=head;
    for(int i=1;i<ans.size();i++){
        end=new LL(ans[i],nullptr);
        temp->next=end;
        temp=end;
    }
    //head=head->removeHead(head);
    //head=head->removetail(head);
    //head=head->removek(head,12);
    //head=head->removeEl(head,16);
    //head=head->insertHead(head,0);
    //head=head->insertTail(head,7);
    head=head->insertK(head,7,0);
    head->printLL(head);
    return 0;
}