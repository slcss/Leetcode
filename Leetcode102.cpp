// Leetcode102.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> allNodes;
    if (!root) return allNodes;
    queue<pair<TreeNode*, int>> qTreeNodes;
    qTreeNodes.push({ root, 0 });

    int level = 0;
    vector<int> nodesInSameLevel;
    while (!qTreeNodes.empty())
    {
        if (!qTreeNodes.front().first)
        {
            qTreeNodes.pop();
        }
        else
        {
            int index = qTreeNodes.front().second;
            TreeNode* node = qTreeNodes.front().first;
            if (level != index)
            {
                allNodes.push_back(nodesInSameLevel);
                nodesInSameLevel.clear();
            }
            nodesInSameLevel.push_back(node->val);
            qTreeNodes.pop();
            qTreeNodes.push({ node->left, index + 1 });
            qTreeNodes.push({ node->right, index + 1 });
            level = index;
        }
    }
    allNodes.push_back(nodesInSameLevel);

    return allNodes;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>>ans;
    if (!root)return ans;
    queue<TreeNode*>q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        vector<int>v;
        while (sz--) {
            TreeNode* f = q.front();
            v.push_back(q.front()->val);
            q.pop();
            if (f->left)q.push(f->left);
            if (f->right)q.push(f->right);

        }
        ans.push_back(v);
    }
    return ans;
}

void dfs(TreeNode* root, vector<vector<int>>& ans, int d = 0) {
    if (!root)return;
    if (d >= ans.size())ans.push_back({});
    ans[d].push_back(root->val);
    dfs(root->left, ans, d + 1);
    dfs(root->right, ans, d + 1);
}
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>>ans;
    if (!root)return ans;
    if (!root)return ans;
    dfs(root, ans);
    return ans;
}

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
