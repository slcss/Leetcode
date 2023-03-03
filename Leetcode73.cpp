// Leetcode73.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace::std;

void setZeroes(vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    int m = matrix[0].size();
    bool flag1 = false, flag2 = false;
    for (int i = 0; i < n; i++) {
        if (matrix[i][0] == 0) {
            flag1 = true;
        }
    }
    for (int j = 0; j < m; j++) {
        if (matrix[0][j] == 0) {
            flag2 = true;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    if (flag1 == true) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
    if (flag2 == true) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
}


int main()
{
    vector<vector<int>> matrix{ {0,1,2,0}, {3,4,5,2}, {1,3,1,5} };

    setZeroes(matrix);
    
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
