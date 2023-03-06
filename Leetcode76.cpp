// Leetcode76.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using namespace::std;

string minWindow(string s, string t)
{
    string res = "";
    int minWinSize = INT_MAX;

    int lengthT = t.size();  //the length of string t
    unordered_map<char, int>  mapT, mapTemp;  //strT is a map of string t; strTtemp is a map of substr
    for (auto ch : t)
    {
        ++mapT[ch];
        //strTtemp[ch]=0;
    }

    queue<int> qS;
    int lengthTemp = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (mapT.find(s[i]) != mapT.end())
        {
            qS.push(i);
            ++mapTemp[s[i]];
            if (mapTemp[s[i]] <= mapT[s[i]]) ++lengthTemp; //if substr doesn't have enough same characters, ++lengthTemp
            //ready to pop from qS
            while (lengthTemp == lengthT)
            {
                int popIndex = qS.front();
                char popChar = s[popIndex];

                qS.pop();
                if (minWinSize > i - popIndex + 1)
                {
                    minWinSize = i - popIndex + 1;
                    res = s.substr(popIndex, minWinSize);
                }

                --mapTemp[popChar];
                if (mapTemp[popChar] < mapT[popChar])
                    --lengthTemp;
            }
        }
    }
    return res;
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    string res = minWindow(s, t);
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
