// Leetcode98.cpp : This file contains the 'main' function. Program execution begins and ends there.
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


bool isValidBST(TreeNode* root) {
    bool res = true;
    int min, max;
    res = isValidBST(root, min, max);

    return res;
}

bool isValidBST(TreeNode* root, int& min, int& max) {
    bool res = true;
    if (root->left == nullptr && root->right == nullptr) {
        min = root->val; max = root->val; return true;
    }

    if (root->left)
    {
        if (root->left->val > root->val) return false;
        int minL, maxL;
        bool resLeft = isValidBST(root->left, minL, maxL);
        res = res && resLeft && maxL < root->val;  if (!res) return res;
        min = minL;
    }
    else min = root->val;
    if (root->right)
    {
        if (root->right->val < root->val) return false;
        int minR, maxR;
        bool resRight = isValidBST(root->right, minR, maxR);
        res = res && resRight && minR > root->val;  if (!res) return res;
        max = maxR;
    }
    else max = root->val;
    return res;
}



bool isbst(TreeNode* root, long min, long max) {
    // Base Case
    if (root == NULL) return true;

    if (root->val > min && root->val < max) {
        bool left = isbst(root->left, min, root->val);
        bool right = isbst(root->right, root->val, max);

        return left && right;
    }
    else {
        return false;
    }
}
bool isValidBST(TreeNode* root) {
    return isbst(root, LONG_MIN, LONG_MAX);
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
