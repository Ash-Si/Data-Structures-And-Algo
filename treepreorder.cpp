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

void recpreorder(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    if (root->left)
        recpreorder(root->left);
    if (root->right)
        recpreorder(root->right);
}

void iterpreorder(TreeNode *root)
{
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *temp = st.top();
        st.pop();
        cout << temp->data << " ";
        if (temp->right)
            st.push(temp->right);
        if (temp->left)
            st.push(temp->left);
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
    recpreorder(root);
    cout<<endl;
    iterpreorder(root);
    return 0;
}