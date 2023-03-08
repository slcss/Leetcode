// Leetcode79.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace::std;

bool exist(vector<vector<char>>& board, string word)
{
    bool res = false;
    int rows = board.size();
    int cols = board[0].size();
    vector<vector<int>> mask = vector<vector<int>>(rows, vector<int>(cols, 0));

    int wordLenth = word.size();
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (board[i][j] == word[0])
            {
                mask[i][j] = 1;
                res = exist(board, mask, i, j, word, 1);
                if (res == true) return res;
                mask[i][j] = 0;
            }
        }
    }
    return res;
}

bool exist(vector<vector<char>>& board, vector<vector<int>>& mask, int row, int col, string& word, int index)
{
    bool res = false;
    if (index == word.size())
        return true;

    //check up
    if (row - 1 >= 0 && mask[row - 1][col] == 0 && board[row - 1][col] == word[index])
    {
        mask[row - 1][col] = 1;
        res = exist(board, mask, row - 1, col, word, index + 1);
        if (res == true) return res;
        mask[row - 1][col] = 0;
    }
    //check bottom
    if (row + 1 < board.size() && mask[row + 1][col] == 0 && board[row + 1][col] == word[index])
    {
        mask[row + 1][col] = 1;
        res = exist(board, mask, row + 1, col, word, index + 1);
        if (res == true) return res;
        mask[row + 1][col] = 0;
    }
    //check left
    if (col - 1 >= 0 && mask[row][col - 1] == 0 && board[row][col - 1] == word[index])
    {
        mask[row][col - 1] = 1;
        res = exist(board, mask, row, col - 1, word, index + 1);
        if (res == true) return res;
        mask[row][col - 1] = 0;
    }
    //check right
    if (col + 1 < board[0].size() && mask[row][col + 1] == 0 && board[row][col + 1] == word[index])
    {
        mask[row][col + 1] = 1;
        res = exist(board, mask, row, col + 1, word, index + 1);
        if (res == true) return res;
        mask[row][col + 1] = 0;
    }
    return res;
}

int main()
{
    vector<vector<char>> board = { {'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'} };
    string word = "ABCCED";

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
