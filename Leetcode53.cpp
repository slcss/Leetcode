// Leetcode53.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace::std;


int maxSubArray(vector<int>& nums)
{
    int sumMax = INT_MIN, sumMaxTmp = 0;

    int begin = 0, end = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] <= 0)
        {
            sumMaxTmp += nums[i];
            sumMax = max(sumMax, sumMaxTmp);
            if (begin == end)
            {
                sumMaxTmp = 0;
                ++begin;
                ++end;
            }
            else //begin < end
            {
                if (sumMaxTmp <= 0)
                {
                    sumMaxTmp = 0;
                    ++begin;
                    ++end;
                }
                else //sumMaxTmp > 0
                {
                    ++end;
                }
            }
        }
        else //nums[i] > 0
        {
            sumMaxTmp += nums[i];
            sumMax = max(sumMax, sumMaxTmp);
            ++end;
        }
    }

    return sumMax;
}

int maxSubArray1(vector<int>& nums)
{
    int curMax = 0, maxTillNow = INT_MIN;
    for (auto c : nums)
        curMax = max(c, curMax + c),
        maxTillNow = max(maxTillNow, curMax);
    return maxTillNow;
}

int main()
{
    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };

    int res = maxSubArray(nums);

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
