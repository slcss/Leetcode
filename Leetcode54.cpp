// Leetcode54.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace::std;

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int nums = rows * cols;

    vector<int> spiral;
    vector<vector<int>> mask;
    for (int i = 0; i < rows; ++i)
        mask.push_back(vector<int>(cols, 0));


    int direction = 0;
    int startX = 0, startY = 0;
    while (spiral.size() < nums)
    {
        switch (direction)
        {
        case 0:  //row,left to right
            int col;
            for (col = startY; col < cols; ++col)
            {
                if (!mask[startX][col])
                {
                    mask[startX][col] = 1;
                    spiral.push_back(matrix[startX][col]);
                }
                else
                    break;
            }
            ++startX;
            startY = col - 1;
            direction = 1;
            break;

        case 1: //col,top to bottom
            int row1;
            for (row1 = startX; row1 < rows; ++row1)
            {
                if (!mask[row1][startY])
                {
                    mask[row1][startY] = 1;
                    spiral.push_back(matrix[row1][startY]);
                }
                else
                    break;
            }
            startX = row1 - 1;
            --startY;
            direction = 2;
            break;

        case 2: //row,right to left
            int col2;
            for (col2 = startY; col2 >= 0; --col2)
            {
                if (!mask[startX][col2])
                {
                    mask[startX][col2] = 1;
                    spiral.push_back(matrix[startX][col2]);
                }
                else
                    break;
            }
            --startX;
            startY = col2 + 1;
            direction = 3;
            break;

        case 3: //col, bottom to up
            int row3;
            for (row3 = startX; row3 >= 0; --row3)
            {
                if (!mask[row3][startY])
                {
                    mask[row3][startY] = 1;
                    spiral.push_back(matrix[row3][startY]);
                }
                else
                    break;
            }
            startX = row3 + 1;
            ++startY;
            direction = 0;
            break;
        }
    }


    return spiral;

}

int main()
{
    vector<vector<int>> matrix = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };

    vector<int> spiral = spiralOrder(matrix);

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
