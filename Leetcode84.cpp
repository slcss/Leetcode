// Leetcode84.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace::std;

int largestRectangleArea(vector<int>& heights)
{
    stack<pair<int, int>> stackHeight;
    int area = INT_MIN;
    stackHeight.push({ heights[0], 1 });

    for (int i = 1; i < heights.size(); ++i)
    {
        if (heights[i] >= stackHeight.top().first)
            stackHeight.push({ heights[i], i + 1 });
        else
        {
            int tempIndex = 0;
            while (!stackHeight.empty() && stackHeight.top().first > heights[i]  )
            {
                tempIndex = stackHeight.top().second;
                area = max(area, stackHeight.top().first * (i+1 - tempIndex));
                stackHeight.pop();
            }
            stackHeight.push({ heights[i], tempIndex });
        }
    }

    int tempIndex = heights.size() + 1;
    while (!stackHeight.empty())
    {
        area = max(area, stackHeight.top().first * (tempIndex - stackHeight.top().second));
        stackHeight.pop();
    }

    return area;
}

int main()
{
    vector<int> heights = { 5,5,1,7,1,1,5,2,7,6 };

    int res = largestRectangleArea(heights);

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
