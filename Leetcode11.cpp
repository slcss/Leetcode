// Leetcode6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace::std;

int maxArea(vector<int>& height) 
{
    int area = 0;
    for (auto i = height.begin(); i != height.end(); ++i)
    {
        for (auto j = i + 1; j != height.end(); ++j)
        {
            int areaTmp = min(*i, *j) * (j - i);
            area = max(area, areaTmp);
        }
    }
    return area;
}

int maxAreaBetter(vector<int>& height)
{
    int area = 0;
    auto start = height.begin();
    auto end = height.end() - 1;

    while (start != end)
    {
        int areaTmp = min(*start, *end) * (end - start);
        area = max(area, areaTmp);

        if (*start <= *end)
        {
            start += 1;
        }
        else
        {
            end -= 1;
        }
    }
    return area;
}

int main()
{

    vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };

    //int area = maxArea(height);
    int area = maxAreaBetter(height);

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
