// Leetcode101.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    queue<TreeNode*> queue;
    queue.push(root->left);
    queue.push(root->right);
    while (!queue.empty()) {
        TreeNode* left = queue.front(); queue.pop();
        TreeNode* right = queue.front(); queue.pop();
        if (!left && !right) continue;
        if (!left || !right) return false;
        if (left->val != right->val) return false;
        queue.push(left->left);
        queue.push(right->right);
        queue.push(left->right);
        queue.push(right->left);
    }
    return true;
}

bool isSymmetric(TreeNode* root) {
    return isSymmetric(root->left, root->right);
}
bool isSymmetric(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right == nullptr) return true;
    if (left != nullptr && right != nullptr) {
        return left->val == right->val && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
    else return false;
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
