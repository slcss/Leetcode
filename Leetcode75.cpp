// Leetcode75.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace::std;

void sortColors(vector<int>& nums)
{
    int left = 0, right = nums.size() - 1;
    // while(nums[left]==0)
    // {
    //     ++left;
    //     if(left>nums.size()-1) break;
    // }
    // while(nums[right]==2)
    // {
    //     --right;
    //     if(right<0) break;
    // }

    for (int i = left; i <= right;)
    {
        if (0 == nums[i])
        {
            swap(nums[i], nums[left]);
            ++left;
            ++i;
        }
        else if (2 == nums[i])
        {
            swap(nums[i], nums[right]);
            --right;
        }
        else
            ++i;
        // else
        // {
        //     if(nums[i]>nums[right])
        //     {
        //         swap(nums[i],nums[right]);
        //         if(0 == nums[i]) ++left;
        //     }
        // }
    }
}

int main()
{
    vector<int> nums = { 2,0,2,1,1,0 };

    sortColors(nums);

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
