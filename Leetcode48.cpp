// Leetcode48.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace::std;


void rotate(vector<vector<int>>& matrix)
{
    int size = matrix.size();
    int halfSize = (matrix.size() + 1) / 2;

    for (int i = 0; i < halfSize; ++i)
    {
        if (size % 2 && i == halfSize - 1)
            continue;

        for (int j = 0; j < halfSize; ++j)
        {
            int temp1 = matrix[i][j];
            matrix[i][j] = matrix[size - j - 1][i];

            int temp2 = matrix[j][size - i - 1];
            matrix[j][size - i - 1] = temp1;

            temp1 = matrix[size - i - 1][size - j - 1];
            matrix[size - i - 1][size - j - 1] = temp2;

            matrix[size - j - 1][i] = temp1;
        }

    }
}

int main()
{
    vector<vector<int>> matrix = { {5,1,9,11} ,{2,4,8,10},{13,3,6,7},{15,14,12,16} };

    rotate(matrix);

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
