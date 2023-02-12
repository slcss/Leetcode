// Leetcode20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace::std;


char getAnother(char s)
{
    if (s == '}')
        return '{';
    if (s == ']')
        return '[';
    if (s == ')')
        return '(';

    return {};
}


bool isValid(string s)
{
    vector<char> data; //stack<char> st;

    for (auto ch : s)
    {
        if (ch == '{' || ch == '(' || ch == '[')
        {
            data.push_back(ch);
        }
        else
        {
            if (0 == data.size())
                return false;
            if (data.back() != getAnother(ch))
                return false;
            else
                data.pop_back();
        }
    }
    if (data.size())
        return false;

    return true;   //return data.empty()

}

int main()
{
    string s = "()[]{}";

    bool res = isValid(s);

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
