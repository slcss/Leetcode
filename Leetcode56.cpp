// Leetcode56.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    vector<vector<int>> vmerge;
    //sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {return a[0] < b[0]; });
    sort(intervals.begin(), intervals.end());

    if (1 == intervals.size())
        return intervals;

    vector<int> temp(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i)
    {
        if (intervals[i][0] >= temp[0] && intervals[i][0] <= temp[1])
        {
            temp[1] = max(temp[1], intervals[i][1]);
        }
        else
        {
            vmerge.push_back(temp);
            temp = intervals[i];
        }
    }
    vmerge.push_back(temp);
    return vmerge;
}


int main()
{
    vector<vector<int>> intervals = { {2,6} ,{1,3},{8,10},{15,18} };

    vector<vector<int>> res = merge(intervals);

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
