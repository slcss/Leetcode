// Leetcode17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>


using namespace::std;


vector<string> iterations(vector<string> strAll, vector<char> chAll)
{
    vector<string> res;

    if (0 == strAll.size())
    {
        for (auto ch : chAll)
        {
            string a;
            a = ch;
            res.push_back(a);
        }
        return res;
    }
    for (auto str : strAll)
    {
        for (auto ch : chAll)
        {
            res.push_back(str + ch);
        }
    }
    return res;
}


vector<string> letterCombinations(string digits) 
{
    vector<vector<char>> data;

    if (0 == digits.length())
        return {};

    for (auto ch : digits)
    {
        switch (ch)
        {
        case '2':
            data.push_back(vector<char>{'a', 'b', 'c'});
            break;
        case '3':
            data.push_back(vector<char>{'d', 'e', 'f'});
            break;
        case '4':
            data.push_back(vector<char>{'g', 'h', 'i'});
            break;
        case '5':
            data.push_back(vector<char>{'j', 'k', 'l'});
            break;
        case '6':
            data.push_back(vector<char>{'m', 'n', 'o'});
            break;
        case '7':
            data.push_back(vector<char>{'p', 'q', 'r', 's'});
            break;
        case '8':
            data.push_back(vector<char>{'t', 'u', 'v'});
            break;
        case '9':
            data.push_back(vector<char>{'w', 'x', 'y', 'z'});
            break;
        default:
            break;
        }
    }

    vector<string> res = {};

    for (auto vch : data)
    {
        res = iterations(res, vch);
    }



    return res;
}


int main()
{
    string sigits = "245";

    vector<string> res = letterCombinations(sigits);

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
