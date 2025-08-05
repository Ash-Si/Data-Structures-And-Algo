#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    TreeNode *left, *right;
    int data;
    TreeNode(int d)
    {
        left = right = nullptr;
        data = d;
    }
};

vector<vector<int>> verticalview(TreeNode *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        TreeNode *temp = q.front().first;
        int row = q.front().second.second, col = q.front().second.first;
        q.pop();
        nodes[col][row].insert(temp->data);
        if (temp->left != nullptr)
            q.push({temp->left, {col - 1, row + 1}});
        if (temp->right != nullptr)
            q.push({temp->right, {col + 1, row + 1}});
    }
    vector<vector<int>> ans;
    for (auto col : nodes)
    {
        vector<int> temp;
        for (auto row : col.second)
        {
            for (auto val : row.second)
                temp.push_back(val);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<vector<int>> ans = verticalview(root);
    for (auto row : ans)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}
