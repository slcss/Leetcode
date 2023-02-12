// Leetcode31.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace::std;

void nextPermutation(vector<int>& nums)
{
    if (1 == nums.size())
        return;
    for (int i = nums.size() - 1; i != 0; --i)
    {
        if (nums[i - 1] < nums[i])
        {

            int j = i, k = nums.size() - 1;
            while (j < k)
            {
                int temp = nums[j];
                nums[j] = nums[k];
                nums[k] = temp;
                ++j;
                --k;
            }
            j = i;
            while (j < nums.size())
            {
                if (nums[i - 1] < nums[j])
                {
                    int temp = nums[i - 1];
                    nums[i - 1] = nums[j];
                    nums[j] = temp;
                    
                    return;
                }
                ++j;
            }
        }
    }

    int i = 0, j = nums.size() - 1;
    while (i < j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        ++i;
        --j;
    }

}

int main()
{
    vector<int> nums = { 2,3,1 };

    nextPermutation(nums);

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
