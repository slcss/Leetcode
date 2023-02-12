// Leetcode5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace::std;

string longestPalindrome(string s)
{
    int maxLength = 0;
    string maxString = "";

    if (1 == s.size())
        return s;

    for (auto it = s.begin(); it != s.end(); ++it)
    {
        int lengthTmp = 0;
        string stringTmp = "";
        if (it == s.begin())
        {
            if (*it == *(it + 1))
            {
                lengthTmp = 2;
                stringTmp = s.substr(it - s.begin(), lengthTmp);
            }
            else
            {
                lengthTmp = 1;
                stringTmp = s.substr(it - s.begin(), lengthTmp);
            }           
        }
        else if (it == s.end() - 1)
        {
            lengthTmp = 1;
            stringTmp = s.substr(it - s.begin(), lengthTmp);
        }
        else
        {            
            auto its = it, ite = it;
            while (ite != s.end())
            {
                if (*its == *ite)
                {
                    if (its == s.begin())
                    {
                        lengthTmp = ite + 1 - its;
                        stringTmp = s.substr(its - s.begin(), lengthTmp);
                        break;
                    }
                    its -= 1;
                    ite += 1;
                }
                else
                {
                    lengthTmp = ite - (its + 1);
                    stringTmp = s.substr(its + 1 - s.begin(), lengthTmp);
                    break;
                }
            }
            if (ite == s.end())
            {
                lengthTmp = ite - (its + 1);
                stringTmp = s.substr(its + 1 - s.begin(), lengthTmp); 
            }                

            int lengthTmp1 = 0;
            string stringTmp1 = "";
            
            if (*it == *(it + 1))//even palindrome
            {
                auto its = it, ite = it + 1;
                while (ite != s.end())
                {
                    if (*its == *ite)
                    {
                        if (its == s.begin())
                        {
                            lengthTmp1 = ite + 1 - its;
                            stringTmp1 = s.substr(its - s.begin(), lengthTmp1);
                            break;
                        }
                        its -= 1;
                        ite += 1;
                    }
                    else
                    {
                        lengthTmp1 = ite - (its + 1);
                        stringTmp1 = s.substr(its + 1 - s.begin(), lengthTmp1);
                        break;
                    }
                }
                if (ite == s.end())
                {
                    lengthTmp1 = ite - (its + 1);
                    stringTmp1 = s.substr(its + 1 - s.begin(), lengthTmp1);
                }                
            }

            if (lengthTmp <= lengthTmp1)
            {
                lengthTmp = lengthTmp1;
                stringTmp = stringTmp1;
            }
        }

        if (maxLength<= lengthTmp)
        {
            maxLength = lengthTmp;
            maxString = stringTmp;
        }
    }

    return maxString;
}


string longestPalindromeBetter(string s)
{
    int len = s.size();

    vector<vector<int>> dp;

    for (int i = 0; i < len; ++i)
    {
        vector<int> dp1(len, 0);
        dp.push_back(dp1);
    }



    //int dp[len][len];
    //memset(dp, 0, sizeof(dp));
    int end = 1;
    int start = 0;

    for (int i = 0; i < len; i++) //length = 1
    {
        dp[i][i] = 1;
    }
    for (int i = 0; i < len - 1; i++) //length = 2
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = 1; start = i; end = 2;
        }
    }

    for (int j = 2; j < len; j++)  //length = 3, 4, 5.....
    {
        for (int i = 0; i < len - j; i++)
        {
            int left = i; //start point
            int right = i + j;  //ending point

            if (dp[left + 1][right - 1] == 1 && s[left] == s[right])
            {
                dp[left][right] = 1; start = i; end = j + 1;
            }
        }
    }
    return s.substr(start, end);
}



int main()
{
    string a = "cbbd";

    //string result = longestPalindrome(a);
    string result = longestPalindromeBetter(a);

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
