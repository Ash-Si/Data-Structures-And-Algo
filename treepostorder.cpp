#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left, *right;
    TreeNode(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

void recpostorder(TreeNode* root){
    if(!root) return;
    recpostorder(root->left);
    recpostorder(root->right);
    cout<<root->data<<" ";
}

void iterpostorder(TreeNode* root){
    stack<TreeNode*> st;
    TreeNode* temp = root;
    vector<int> postorder;
    while(temp || !st.empty()){
        while(temp){
            postorder.push_back(temp->data);
            st.push(temp);
            temp = temp->right;
        }
        temp = st.top();
        st.pop();
        temp=temp->left;
    }
    reverse(postorder.begin(),postorder.end());
    for(auto i : postorder)
        cout<<i<<" ";
}

void stackpostorder(TreeNode* root){
    stack<TreeNode*> s1, s2;
    s1.push(root);
    while(!s1.empty()){
        TreeNode* temp = s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left)
            s1.push(temp->left);
        if(temp->right)
            s1.push(temp->right);   
    }
    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    recpostorder(root);
    cout<<endl;
    iterpostorder(root);
    cout<<endl;
    stackpostorder(root);
    return 0;
}