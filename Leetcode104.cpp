// Leetcode104.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

// int maxDepth(TreeNode* root) {
    //     int depth=0;
    //     if(!root) return depth;
    //     queue<TreeNode*> qTree;
    //     qTree.push(root);

    //     while(!qTree.empty())
    //     {
    //         int size = qTree.size();
    //         while(size--)
    //         {
    //             if(qTree.front()->left) qTree.push(qTree.front()->left);
    //             if(qTree.front()->right) qTree.push(qTree.front()->right);
    //             qTree.pop();
    //         }
    //         ++depth;
    //     }


    //     return depth;
    // }


int maxDepth(TreeNode* root) {

    if (root == NULL) return 0;

    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
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
