// Leetcode15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace::std;


vector<vector<int>> threeSum(vector<int>& nums)
{
    
    /*multiset<int> set1;
    for (auto num : nums)
    {
        set1.insert(num);
        cout << num << endl;
    }

    vector<int> sortNums;
    for (auto num : set1)
    {
        sortNums.push_back(num);
        cout << num << endl;
    }*/

    sort(nums.begin(), nums.end());

    
    set<vector<int>> set2;

    for (int i = 1; i <= nums.size() - 2; ++i)
    {
        int left = i - 1, right = i + 1;
        while (left >= 0 && right <= nums.size() - 1)
        {
            if (nums[left] + nums[right] + nums[i] < 0)
            {
                right++;
            }
            else if (nums[left] + nums[right] + nums[i] > 0)
            {
                left--;
            }
            else
            {
                vector<int> each = { nums[left], nums[i], nums[right] };

                set2.insert(each);          
                left--;

            }      

            
        }
        
    }


    vector<vector<int>> all;
    for (auto num : set2)
    {
        all.push_back(num);
    }
    
    return all;
}


int main()
{
    vector<int> nums = { -1,0,1,2,-1,-4,-2,-3,3,0,4 };

    vector<vector<int>> result = threeSum(nums);

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
