// Leetcode78.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace::std;

void subsetsRecursion(vector<vector<int>>& res, vector<int>& nums, int index)
{
    if (res.empty())
    {
        res.push_back(vector<int>{});
        res.push_back(vector<int>{nums[index]});
    }
    else
    {
        int size = res.size();
        for (int i = 0; i < size; ++i)
        {
            vector<int> tmp = res[i];
            tmp.push_back(nums[index]);
            res.push_back(tmp);
        }
    }

    if (index == nums.size() - 1) return;
    subsetsRecursion(res, nums, index + 1);

}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> res;

    subsetsRecursion(res, nums, 0);

    return res;
}

vector<vector<int>> subsetsBetter(vector<int>& nums) {
    vector<vector<int>> subs = { {} };
    for (int num : nums) {
        int n = subs.size();
        for (int i = 0; i < n; i++) {
            subs.push_back(subs[i]);
            subs.back().push_back(num);
        }
    }
    return subs;
}


int main()
{
    vector<int> nums = { 1,2,3 };
    subsets(nums);

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
