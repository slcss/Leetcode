// Leetcode13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace::std;

int romanToInt(string s)
{
    int sum = 0;
    unordered_map<char, pair<int, int>> ch = { {'I',{1,1}},{'V',{2,5}},{'X',{3,10}},{'L',{4,50}},{'C',{5,100}},{'D',{6,500}},{'M',{7,1000}} };

    auto last = *s.rbegin();
    for (auto it = s.rbegin(); it != s.rend(); ++it)
    {
        auto cur = *it;
        if (ch[cur].first < ch[last].first)
            sum -= ch[cur].second;
        else
            sum += ch[cur].second;
        last = cur;
    }

    return sum;
}

int main()
{
    string s = "MCMXCIV";
    int res = romanToInt(s);
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
