// Leetcode34.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace::std;

int searchFirstHalf(vector<int>& nums, int front, int end, int target)
{
    int res = -1;

    if (front == end)
        return front;

    while (front <= end)
    {
        int mid = (front + end) / 2;
        if (target == nums[mid])
        {
            res = searchFirstHalf(nums, front, mid, target);
            return res;
        }
        else
        {
            res = searchFirstHalf(nums, mid + 1, end, target);
            return res;
        }
    }

    return res;
}

int searchSecondHalf(vector<int>& nums, int front, int end, int target)
{
    int res = -1;

    if (front == end)
        return end;

    while (front <= end)
    {
        int mid = (front + end+1) / 2;
        if (target == nums[mid])
        {
            res = searchSecondHalf(nums, mid, end, target);
            return res;
        }
        else
        {
            res = searchSecondHalf(nums, front, mid - 1, target);
            return res;
        }
    }

    return res;
}

vector<int> searchRange(vector<int>& nums, int target) 
{
    int leftEdge = -1, rightEdge = -1;
    int front = 0, end = nums.size() - 1;

    while (front <= end)
    {
        int mid = (front + end) / 2;

        if (target == nums[mid])
        {
            leftEdge = searchFirstHalf(nums, front, mid, target);
            rightEdge = searchSecondHalf(nums, mid, end, target);
            break;
        }
        else if (target < nums[mid])
            end = mid - 1;
        else
            front = mid + 1;

    }

    return { leftEdge, rightEdge };
}

int main()
{
    vector<int> nums = {  };
    int target = 6;

    vector<int> range = searchRange(nums, target);

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
