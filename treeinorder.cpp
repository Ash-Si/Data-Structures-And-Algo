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

void recinorder(TreeNode* root){
    if(!root) return;
    recinorder(root->left);
    cout<<root->data<<" ";
    recinorder(root->right);
}

void iterinorder(TreeNode* root){
    stack<TreeNode*> st;
    TreeNode* temp = root;
    while(temp || !st.empty()){
        while(temp){
            st.push(temp);
            temp = temp->left;
        }
        temp = st.top();
        st.pop();
        cout<<temp->data<<" ";
        temp=temp->right;
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
    recinorder(root);
    cout<<endl;
    iterinorder(root);
    return 0;
}