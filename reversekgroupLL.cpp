#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
    int data;
    ListNode* next;

    ListNode(int data1, ListNode *next1){
        data=data1;
        next=next1;
    }

    void printLL(ListNode* head){
        for(auto i=head;i!=nullptr;i=i->next)
            cout<<i->data<<" ";
    }

    ListNode* reverseKGroup1(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode* dummy = new ListNode(0,nullptr);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;
        while (true) {
            ListNode* kth = prevGroupEnd;
            for (int i = 0; i < k; ++i) {
                kth = kth->next;
                if (!kth) {
                    ListNode* result = dummy->next;
                    delete dummy;
                    return result;
                }
            }
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroupStart = kth->next;
            ListNode* prev = nextGroupStart;
            ListNode* curr = groupStart;
            while (curr != nextGroupStart) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            prevGroupEnd->next = kth;
            prevGroupEnd = groupStart;
        }
        return dummy->next;
    }

    ListNode* rev(ListNode* head){
        ListNode* temp=head,* prev=NULL;
        while(temp){
            ListNode* curr=temp;
            temp=temp->next;
            curr->next=prev;
            prev = curr;
        }
        return prev;
    }

    ListNode* split(ListNode* head, int k){
        for(int i=1;i<k && head->next;i++){
            head=head->next;
        }
        ListNode *right=head->next;
        head->next=nullptr;
        return right;
    }

    ListNode* reverseKGroup2(ListNode* head, int k) {
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode* temp=head;
        ListNode* dummy=new ListNode(0,nullptr), *tail=dummy;
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        temp=head;
        while(temp && count>=k){
            ListNode* left= temp;
            temp = split(temp,k);
            tail->next= rev(left);
            tail=left;
            count-=k;
        }
        if(temp)
            tail->next=temp;
        head=dummy->next;
        delete dummy;
        return head;
    }

};

    int main(){
        vector<int> ans= {1,2,3,4,5,6};
        ListNode* head=new ListNode(1,nullptr);
        ListNode* temp,*end;
        temp=head;
        for(int i=1;i<ans.size();i++){
            end=new ListNode(ans[i],nullptr);
            temp->next=end;
            temp=end;
        }
        head=head->reverseKGroup2(head,2);
        head->printLL(head);
        return 0;
    }