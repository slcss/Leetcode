// Leetcode35.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace::std;

int searchInsert(vector<int>& nums, int target)
{

    int front = 0, end = nums.size() - 1;

    while (front <= end)
    {

        int mid = front + (end - front) / 2;

        if (target == nums[mid])
            return mid;
        else if (target < nums[mid])
            end = mid - 1;
        else
            front = mid + 1;
    }



    return front;
}


int main()
{
    vector<int> nums = { 1,3,5,6 };
    int target = 2;

    int res = searchInsert(nums, target);

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
