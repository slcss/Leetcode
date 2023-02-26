// Leetcode62.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace::std;

int uniquePaths(int m, int n)
{
    /*vector<vector<int>> grid;
    vector<int> line(n,0);
    for(int i=0;i<m;++i)
    {
        grid.push_back(line);
    }*/

    vector<vector<int>> grid(m, vector<int>(n, 0));

    grid[0][0] = 1;
    for (int row = 0; row < m; ++row)
    {
        for (int col = 0; col < n; ++col)
        {
            int up = row - 1 >= 0 ? grid[row - 1][col] : 0;
            int left = col - 1 >= 0 ? grid[row][col - 1] : 0;
            grid[row][col] += up + left;
        }
    }

    return grid[m - 1][n - 1];

}

int main()
{
    int res = uniquePaths(3, 7);

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
