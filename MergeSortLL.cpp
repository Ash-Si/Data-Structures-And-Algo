#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int data;
    ListNode* next;
    ListNode(int data1,ListNode *next1){
        data=data1;
        next=next1;
    }
    void printLL(ListNode* head){
        for(ListNode* i=head;i!=nullptr;i=i->next)
            cout<<i->data<<" ";
    }
};
ListNode* merge(ListNode* L1, ListNode* L2){
    ListNode *dummy=new ListNode(0,nullptr), *tail=dummy;
    while(L1 && L2){
        if(L1->data<=L2->data){
            tail->next=L1;
            L1=L1->next;
        } else {
            tail->next=L2;
            L2=L2->next;
        }
        tail=tail->next;
    }
    if (L1)
        tail->next=L1;
    if (L2)
        tail->next=L2;
    return dummy->next;
}
ListNode* split(ListNode* head, int size){
    if(!head) return NULL;
    for(int i=1;i<size && head->next;i++){
        head=head->next;
    }
    ListNode* second=head->next;
    head->next=nullptr;
    return second;
}
ListNode* sortList(ListNode* head) { 
    int n=0;
    ListNode* temp=head, *dummy=new ListNode(0,head);
    while(temp){
        n++;
        temp=temp->next;
    }
    for(int size=1;size<n;size*=2){
        ListNode *tail=dummy;
        ListNode *curr=dummy->next;
        while(curr){
            ListNode *left=curr;
            ListNode *right=split(curr,size);
            curr=split(right,size);

            tail->next=merge(left,right);
            while(tail->next)
                tail=tail->next;
        }
    }
    head=dummy->next;
    delete dummy;
    return head;
}
ListNode* middle(ListNode* head){
    ListNode* slow=head, *fast=head;
    while(fast && fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
ListNode* sortList2(ListNode* head){
    if(!head || !head->next) return head;
    ListNode* mid=middle(head);
    ListNode* midnext=mid->next;
    mid->next=NULL;
    ListNode* L1= sortList2(head);
    ListNode* L2= sortList2(midnext);
    return merge(L1,L2);
}
int main(){
    vector<int> ans= {4,2,1,0};
    ListNode* head=new ListNode(ans[0],nullptr);
    ListNode* temp,*end;
    temp=head;
    for(int i=1;i<ans.size();i++){
        end=new ListNode(ans[i],nullptr);
        temp->next=end;
        temp=end;
    }
    head=sortList2(head);
    head->printLL(head);
}