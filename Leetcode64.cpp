// Leetcode64.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace::std;

/*int minPathSum(vector<vector<int>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        for(int row = rows-1;row>=0;--row)
        {
            for(int col=cols-1;col>=0;--col)
            {
                if(row == rows-1 && col == cols-1) continue;
                int right = col+1>=cols? INT_MAX:grid[row][col+1];
                int down = row+1>=rows? INT_MAX:grid[row+1][col];

                grid[row][col] += min(right,down);
            }
        }

        return grid[0][0];
    }*/

int minPathSum(vector<vector<int>>& grid) {
    int i, j, m = grid.size(), n = grid[0].size();
    for (j = 1; j < n; j++) {
        grid[0][j] += grid[0][j - 1];
    }
    for (i = 1; i < m; i++) {
        grid[i][0] += grid[i - 1][0];
    }
    for (i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
            grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
        }
    }
    return grid[m - 1][n - 1];
}


int main()
{
    vector<vector<int>> grid{ {1,3,1},{1,5,1},{4,2,1} };

    int res = minPathSum(grid);

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
