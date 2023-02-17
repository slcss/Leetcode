// Leetcode45.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace::std;


int minimumJumps(vector<int>& nums, int index)
{
    int jumps = 1;
    int smallestIndex = index;
    for (int i = index; i >= 0; --i)
    {
        if (i + nums[i] >= index)
            smallestIndex = min(smallestIndex, i);
    }

    if (!smallestIndex)
        return jumps;

    return jumps + minimumJumps(nums, smallestIndex);
}

int jump(vector<int>& nums)
{
    if (1 == nums.size())
        return 0;
    return minimumJumps(nums, nums.size() - 1);
}

int jumpBetter(vector<int>& nums) //greedy
{
    int reach = 0, count = 0, last = 0;  // reach: maximum reachable index from current position
    // count: number of jumps made so far
    // last: rightmost index that has been reached so far
    for (int i = 0; i < nums.size() - 1; i++) {  // loop through the array excluding the last element
        reach = max(reach, i + nums[i]);  // update reach to the maximum between reach and i+nums[i]
        if (i == last) {  // if i has reached the last index that can be reached with the current number of jumps
            last = reach;  // update last to the new maximum reachable index
            count++;  // increment the number of jumps made so far
        }
    }
    return count;  // return the minimum number of jumps required
}


int main()
{
    vector<int> nums = { 2,3,1,1,4 };
    //int res = jump(nums);
    int res = jumpBetter(nums);

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
