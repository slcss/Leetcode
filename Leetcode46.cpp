// Leetcode46.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>


using namespace::std;

vector<vector<int>> all;
int fullSize = 0;

void recurtion(vector<int>& temp, vector<int>& nums)
{
    if (temp.size() == fullSize)
        all.push_back(temp);

    for (int i = 0; i < nums.size(); ++i)
    {
        temp.push_back(nums[i]);
        vector<int> numsTemp = nums;
        numsTemp.erase(numsTemp.begin() + i);
        recurtion(temp, numsTemp);
        temp.pop_back();
    }
}

void solve(vector<int>& nums, vector<vector<int>>& ans, int index) 
{
    if (index >= nums.size()) {
        ans.push_back(nums);
        return;
    }
    for (int j = index; j < nums.size(); j++) {
        swap(nums[index], nums[j]);
        solve(nums, ans, index + 1);
        swap(nums[index], nums[j]);
    }
}
vector<vector<int>> permuteBetter(vector<int>& nums) {
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, ans, index);
    all = ans;
    return ans;
}

vector<vector<int>> permute(vector<int>& nums)
{
    fullSize = nums.size();
    vector<int> temp;
    recurtion(temp, nums);

    return all;
}
int main()
{
    vector<int> nums = { 1,2,3 };

    //permute(nums);
    permuteBetter(nums);
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
