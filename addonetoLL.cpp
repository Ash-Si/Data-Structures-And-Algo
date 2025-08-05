#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

class Solution {
    public:
    void printLL(ListNode* head){
        for(auto* i=head;i!=nullptr;i=i->next)
            cout<<i->val<<" ";
    }
     ListNode *rev(ListNode *head) {
         ListNode *prev = NULL, *temp = head;
         while (temp) {
             ListNode *curr = temp;
             temp = temp->next;
             curr->next = prev;
             prev = curr;
         }
         return prev;
     }
     ListNode *addOne(ListNode *head) {
        if (!head) return new ListNode(1); 

        head = rev(head);  
        ListNode* curr = head;
        int carry = 1;

        while (curr && carry) {
            int sum = curr->val + carry;
            curr->val = sum % 10;
            carry = sum / 10;

            if (!curr->next && carry) {
                curr->next = new ListNode(carry);
                carry = 0;
            }

            curr = curr->next;
        }

        head = rev(head); 
        return head;
     }
 };

 int main(){
    vector<int> numbers={1,2,3};
    ListNode *head= new ListNode(numbers[0]);
    ListNode *temp=head;
    int i=1;
    while(i<numbers.size()){
        ListNode *curr=new ListNode(numbers[i]);
        temp->next=curr;
        temp=temp->next;
    }
    Solution S;
    head=S.addOne(head);
    S.printLL(head);
    return 0;
}