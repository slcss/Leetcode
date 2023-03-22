// Leetcode131.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace::std;

vector<vector<string>> res;

bool isPalindrome(string& s) {
    int i = 0, j = s.size() - 1;
    while (i <= j)
        if (s[i++] != s[j--]) return false;
    return true;
}

void partition(string s, vector<string> vStr) {
    if (s.empty()) {
        res.push_back(vStr);
        return;
    }
    for (int i = 1; i <= s.size(); ++i) {
        string first = s.substr(0, i);
        if (!isPalindrome(first)) continue;
        string second;
        if (i != s.size()) second = s.substr(i, s.size() - i);
        vStr.push_back(first);
        partition(second, vStr);
        vStr.pop_back();
    }

}

vector<vector<string>> partition(string s) {
    partition(s, vector<string>());
    return res;
}

int main()
{
    partition("a");
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
