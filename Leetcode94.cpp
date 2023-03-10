// Leetcode94.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

// vector<int> inorder;
    // vector<int> inorderTraversal(TreeNode* root) {

    //     inorderTraversalRecursion(root);
    //     return inorder;    
    // }

    // void inorderTraversalRecursion(TreeNode* root) {
    //     if(!root) return;

    //     inorderTraversalRecursion(root->left);
    //     inorder.push_back(root->val);
    //     inorderTraversalRecursion(root->right);
    // }



vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inorder;
    if (!root) return inorder;

    stack<pair<TreeNode*, int>> stTree;  //pair<TreeNode*, int>  pointrr to current node, flag to indicate if the left/right node is in the stack
    stTree.push({ root, 0 });

    while (!stTree.empty())
    {
        if (stTree.top().second == 0)
        {
            auto temp = stTree.top();
            stTree.pop();
            if (temp.first->right != nullptr) stTree.push({ temp.first->right, 0 });
            stTree.push(temp); stTree.top().second = 1;
            if (temp.first->left != nullptr) stTree.push({ temp.first->left, 0 });
        }
        else
        {
            inorder.push_back(stTree.top().first->val);
            stTree.pop();
        }
    }

    return inorder;
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
