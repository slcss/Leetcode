// Leetcode32.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace::std;

int longestValidParentheses(string s)
{
    int maxLenth = 0;
    int balance = 0;

    int front = -1, back = -1;
    int lastLenth = 0, tempLenth = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        if ('(' == s[i])
        {
            ++balance;
            if (-1 == front)
                front = i;
            back = i;
        }
        else //s[i] = ')'
        {
            --balance;
            if (!balance)
            {
                back = i;
                tempLenth = back - front + 1;
                maxLenth = max(maxLenth, lastLenth + tempLenth);

                lastLenth = lastLenth + tempLenth;
                front = -1;
                back = -1;
            }
            else if (balance > 0)
            {
                back = i;
                int localBalance = 0;
                for (int j = back; j >= 0; --j)
                {
                    if (')' == s[j])
                        ++localBalance;
                    else
                    {
                        --localBalance;
                        if (!localBalance)
                            maxLenth = max(maxLenth, back - j + 1);
                        else if (localBalance < 0)
                            break;
                    }
                }

            }
            else //balance < 0
            {
                front = -1;
                back = -1;
                balance = 0;
                lastLenth = 0;
            }
        }
    }


    return maxLenth;
}


int longestValidParenthesesBetter(string s)
{
    int maxLength = 0;

    vector<int> vi;
    vi.push_back(-1);

    for (int i = 0; i < s.size(); ++i)
    {
        if ('(' == s[i])
        {
            vi.push_back(i);
        }
        if (')' == s[i])
        {
            vi.pop_back();
            if (!vi.size())
                vi.push_back(i);
            else
                maxLength = max(maxLength, i - vi.back());
        }
    }

    return maxLength;
}


int main()
{

    string s = "((((()())()()))()(()))";

    //int res = longestValidParentheses(s);
    int res = longestValidParenthesesBetter(s);

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
