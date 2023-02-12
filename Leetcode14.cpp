// Leetcode7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace::std;


string longestCommonPrefix(vector<string>& strs) 
{
    //string pre1(strs[0]);

    
    string a = "aa";
    string pre1 = a;
    cout << pre1 << endl;
    //char a = strs[2][3];

    /*if (1 == strs.size())
    {
        pre = strs[0];
        return pre;
    }*/

    for (auto str = strs.begin(); str != strs.end(); ++str)
    {
        int tmpLength = min(pre1.size(), (*str).size());
        if (0 == tmpLength)
        {
            pre1 = "";
            break;
        }            
        for (auto i = tmpLength; i >= 0; --i)
        {
            if (pre1.substr(0, i) == (*str).substr(0, i))
            {
                pre1 = pre1.substr(0, i);
                break;
            }
        }
    }

    return pre1;
}

int main()
{
    //vector<string> strs = { "flower","flow","flight" };
    vector<string> strs = { "abab","aba","" };
    string pre = longestCommonPrefix(strs);
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
