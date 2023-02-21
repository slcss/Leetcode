// Leetcode51.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace::std;


vector<vector<string>> solutions;

void findQueens(vector<vector<int>>& all, int queenNum, int size)
{
    if (size == queenNum)
    {
        vector<string> solution;
        for (auto line : all)
        {
            string lineStr = "";
            for (auto num : line)
            {
                if (2 == num)
                    lineStr.push_back('Q');
                else
                    lineStr.push_back('.');
            }
            solution.push_back(lineStr);
        }

        solutions.push_back(solution);
        return;
    }


    for (int col = 0; col < size; ++col)
    {
        if (!all[queenNum][col])
        {
            vector<vector<int>> temp = all;
            //all[queenNum][col] = 1;
            //deal with all
            for (int i = 0; i < size; ++i)
            {
                all[i][col] = 1;
                all[queenNum][i] = 1;

                if (queenNum - i >= 0 && col - i >= 0)
                    all[queenNum - i][col - i] = 1;
                if (queenNum - i >= 0 && col + i < size)
                    all[queenNum - i][col + i] = 1;
                if (queenNum + i < size && col - i >= 0)
                    all[queenNum + i][col - i] = 1;
                if (queenNum + i < size && col + i < size)
                    all[queenNum + i][col + i] = 1;
            }
            all[queenNum][col] = 2;
            findQueens(all, queenNum + 1, size);
            all = temp;
        }
    }

}

void findQueensBetter(vector<vector<int>>& all, vector<string>& vStr, int queenNum, int size)
{
    if (size == queenNum)
    {
        solutions.push_back(vStr);
        return;
    }

    for (int col = 0; col < size; ++col)
    {
        if (!all[queenNum][col])
        {
            string str(size, '.');
            str[col] = 'Q';
            vStr.push_back(str);
            
            //deal with all
            vector<vector<int>> temp = all;
            for (int i = 0; i < size; ++i)
            {
                all[i][col] = 1;
                all[queenNum][i] = 1;

                if (queenNum - i >= 0 && col - i >= 0)
                    all[queenNum - i][col - i] = 1;
                if (queenNum - i >= 0 && col + i < size)
                    all[queenNum - i][col + i] = 1;
                if (queenNum + i < size && col - i >= 0)
                    all[queenNum + i][col - i] = 1;
                if (queenNum + i < size && col + i < size)
                    all[queenNum + i][col + i] = 1;
            }
            all[queenNum][col] = 2;
            findQueensBetter(all, vStr, queenNum + 1, size);
            all = temp;
            vStr.pop_back();

        }
    }

}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<int>> all;
    vector<int> line(n, 0);
    for (int i = 0; i < n; ++i)
        all.push_back(line);

    //findQueens(all, 0, n);

    vector<string> vStr;
    findQueensBetter(all, vStr, 0, n);

    return solutions;
}

int main()
{
    int n = 5;
    solveNQueens(n);
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
