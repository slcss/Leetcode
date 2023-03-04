// Leetcode74.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace::std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    //find which row
    int front = 0, end = rows - 1;
    while (front <= end)
    {
        int mid = front + (end - front) / 2;
        if (matrix[mid][0] == target)
            return true;
        else if (matrix[mid][0] < target)
            front = mid + 1;
        else
            end = mid - 1;
    }
    if (end < 0) return false;
    int row = end;

    //find which col
    front = 0; end = cols - 1;
    while (front <= end)
    {
        int mid = front + (end - front) / 2;
        if (matrix[row][mid] == target)
            return true;
        else if (matrix[row][mid] < target)
            front = mid + 1;
        else
            end = mid - 1;
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix{ {1,3,5,7}, {10,11,16,20}, {23,30,34,60} };
    int target = 13;
    bool res = searchMatrix(matrix, target);

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
