// Leetcode41.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace::std;

int firstMissingPositive(vector<int>& nums)
{
    int res = 1;
    priority_queue<int, vector<int>, greater<int>> sortArray;
    for (auto num : nums)
    {
        if (num > 0)
            sortArray.push(num);
    }

    int pre = 0;
    if (!sortArray.empty())
        pre = sortArray.top();
    else
        return 1;

    while (!sortArray.empty())
    {
        int now = sortArray.top();
        if (pre != now)
        {
            res++;
            pre = now;
        }

        if (now == res)
            sortArray.pop();
        else
            return res;
    }

    return res + 1;
}

int firstMissingPositiveBetter(vector<int>& nums) 
{
    int i = 0;
    int n = nums.size();
    while (i < n)
    {
        if (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            swap(nums[i], nums[nums[i] - 1]);
        else
            i++;
    }
    for (i = 0; i < n; ++i)
        if (nums[i] != (i + 1))
            return i + 1;
    return n + 1;
}

int main()
{

    //vector<int> nums = { 3,4,-1,1 };
    vector<int> nums = { 0,2,2,1,1 };

    //int res = firstMissingPositive(nums);
    int res = firstMissingPositiveBetter(nums);

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
