// Leetcode124.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    int final = maxPathSum(root, maxSum);
    return max(maxSum, final);
}

int maxPathSum(TreeNode* root, int& maxSum) {
    if (!root) return 0;
    int left = maxPathSum(root->left, maxSum);
    int right = maxPathSum(root->right, maxSum);

    if (left < 0 && right < 0) {
        maxSum = max(maxSum, root->val);
        return root->val;
    }
    else {
        maxSum = max(maxSum, left + right + root->val);
        maxSum = max(maxSum, left + root->val);
        maxSum = max(maxSum, right + root->val);
        return left > right ? left + root->val : right + root->val;
    }
}

//*************************************************

int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    int final = maxPathSum(root, maxSum);
    return max(maxSum, final);
}

int maxPathSum(TreeNode* root, int& maxSum) {
    if (!root) return 0;
    int left = maxPathSum(root->left, maxSum);
    int right = maxPathSum(root->right, maxSum);

    if (left < 0 && right < 0) {
        maxSum = max(maxSum, root->val);
        return root->val;
    }
    else {
        maxSum = max(maxSum, left + right + root->val);
        maxSum = max(maxSum, left + root->val);
        maxSum = max(maxSum, right + root->val);
        return left > right ? left + root->val : right + root->val;
    }
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
