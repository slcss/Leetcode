// Leetcode105.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTree(preorder, inorder, 0, 0, preorder.size());
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int index1, int index2, int length) {
    if (length == 0) return nullptr;

    TreeNode* p = new TreeNode();
    int i;
    for (i = index2; i < index2 + length; ++i)
    {
        if (inorder[i] == preorder[index1])
            break;
    }
    p->val = preorder[index1];
    p->left = buildTree(preorder, inorder, index1 + 1, index2, i - index2);
    p->right = buildTree(preorder, inorder, index1 + i - index2 + 1, i + 1, length - (i - index2 + 1));

    return p;
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
