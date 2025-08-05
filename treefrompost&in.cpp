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

TreeNode *Tree(vector<int> &postorder, int &pS, vector<int> &inorder, int iS, int iE, unordered_map<int, int> &inMap)
{
    if (iS > iE)
        return NULL;
    TreeNode *root = new TreeNode(postorder[pS--]);
    int ele = inMap[root->data];
    root->right = Tree(postorder, pS, inorder, ele + 1, iE, inMap);
    root->left = Tree(postorder, pS, inorder, iS, ele - 1, inMap);
    return root;
}

TreeNode *treebuilder(vector<int> &postorder, vector<int> &inorder)
{
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++)
        inMap[inorder[i]] = i;
    int pS = postorder.size() - 1;
    TreeNode *root = Tree(postorder, pS, inorder, 0, inorder.size() - 1, inMap);
    return root;
}

void printtree(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    if (root->left)
        printtree(root->left);
    else
        cout << "null ";
    if (root->right)
        printtree(root->right);
    else
        cout << "null ";
}

void print(TreeNode *root)
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
        else
            cout << "null ";
        if (temp->left)
            st.push(temp->left);
        else
            cout << "null ";
    }
}

int main()
{
    vector<int> postorder = {9,15,7,20,3};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode *root = treebuilder(postorder, inorder);
    printtree(root);
    cout << endl;
    print(root);
    return 0;
}
