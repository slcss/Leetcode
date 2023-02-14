// Leetcode39.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

vector<vector<int>> all;

void subCombinationSum(vector<int>& lastTemp, vector<int>& candidates, int target, int firstIndex)
{
    lastTemp.push_back(candidates[firstIndex]);

    if (!target)
    {
        all.push_back(lastTemp);
        return;
    }

    for (int i = firstIndex; i < candidates.size(); ++i)
    {
        if (candidates[i] <= target)
        {
            vector<int> temp = lastTemp;
            subCombinationSum(temp, candidates, target - candidates[i], i);
        }
        else
        {
            lastTemp.pop_back();
            break;
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    sort(candidates.begin(), candidates.end());

    for (int i = 0; i < candidates.size(); ++i)
    {
        vector<int> temp;
        if (candidates[i] <= target)
            subCombinationSum(temp, candidates, target - candidates[i], i);
        else
            break;
    }

    return all;

}

int main()
{
    vector<int> candidates = { 2,3,5 };
    int target = 8;
    vector<vector<int>> res = combinationSum(candidates, target);
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
