// Leetcode118.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle;
    triangle.push_back({ 1 });

    if (numRows == 1) return triangle;
    else
    {
        for (int i = 1; i < numRows; ++i)
        {
            triangle.push_back({ 1 });
            for (int index = 0; index < triangle[i - 1].size() - 1; ++index)
                triangle.back().push_back(triangle[i - 1][index] + triangle[i - 1][index + 1]);
            triangle.back().push_back(1);
        }
    }
    return triangle;
}

int main()
{
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
