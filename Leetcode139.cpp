// Leetcode139.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

unordered_map<string, int> mapStr;
bool wordBreak(string s, vector<string>& wordDict) {
    if (s.empty()) return true;
    if (mapStr.find(s) != mapStr.end())
    {
        if (mapStr[s] == 1) return true;
        if (mapStr[s] == 0) return false;
    }

    for (auto& word : wordDict)
    {
        if (s[0] == word[0] && s.find(word) == 0)
        {
            mapStr[word] = 1;
            string rightSubStr = s.substr(word.size());
            if (wordBreak(rightSubStr, wordDict))
            {
                mapStr[s] = 1;
                return true;
            }
            else
            {
                mapStr[rightSubStr] = 0;
                //return false;
            }
        }
    }
    return false;
}

class Solution {
private:
    bool wordBreak(string s, unordered_set<string>& set, vector<int>& memo, int start) {
        if (start == s.size()) {
            return true;
        }
        if (memo[start] != -1) {
            return memo[start];
        }
        for (int i = start; i < s.size(); i++) {
            if (set.count(s.substr(start, i + 1 - start)) && wordBreak(s, set, memo, i + 1)) {
                memo[start] = true;
                return true;
            }
        }
        return memo[start] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size(), -1);
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        return wordBreak(s, set, memo, 0);
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, 0);
        dp[0] = true;
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && set.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
int main()
{
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
