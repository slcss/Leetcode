// Leetcode72.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace::std;

//multimap<vector<int>, int> resMap;
//
//
//int recursion(string& word1, string& word2, int word1_start, int word1_end, int word2_start, int word2_end)
//{
//    vector<int> vword2 = vector<int>(word2.size(), word1_start);
//
//    auto it = resMap.find(vector<int>{word1_start, word1_end, word2_start, word2_end });
//    if (it != resMap.end())
//        return it->second;
//
//    int res = INT_MAX;
//    int steps = 0;
//    if (word1_start > word1_end || word2_start > word2_end)
//    {
//        steps = max(word1_end - word1_start + 1, word2_end - word2_start + 1);
//        steps = steps > 0 ? steps : 0;
//        //resMap.insert({ {word1_start, word1_end, word2_start, word2_end } , steps });
//
//        return steps;
//    }
//
//
//    for (int i = word2_start; i <= word2_end; ++i)
//    {
//        int found = vword2[i];
//        while (found <= word1_end)
//        {
//            found = word1.find(word2[i], found);
//            if (found != std::string::npos && found <= word1_end)
//            {
//
//                int j = 0;
//                while (found + j <= word1_end && i + j <= word2_end)
//                {
//                    if (word1[found + j] != word2[i + j]) break;
//                    ++j;
//                }
//                --j;
//                for (int index = i; index <= i + j; ++index)
//                {
//                    vword2[index] = found + j + 1;
//                }
//
//                //steps = recursion(word1, word2, word1_start, found - 1, word2_start, i - 1) + recursion(word1, word2, found + 1, word1_end, i + 1, word2_end);
//                steps = recursion(word1, word2, word1_start, found - 1, word2_start, i - 1) + recursion(word1, word2, found + j + 1, word1_end, i + j + 1, word2_end);
//                res = min(res, steps);
//                //++found;
//                found = found + j + 1;
//            }
//            else
//            {
//                steps = max(word1_end - word1_start + 1, word2_end - word2_start + 1);
//                res = min(res, steps);
//                break;
//            }
//        }
//    }
//    resMap.insert({ {word1_start, word1_end, word2_start, word2_end } , res });
//
//    return res;
//}
//
//int minDistance(string word1, string word2)
//{
//    int steps = 0;
//    if (word1 == word2)
//        return steps;
//
//    steps = recursion(word1, word2, 0, word1.size() - 1, 0, word2.size() - 1);
//
//    return steps;
//}


int minDistanceBetter(string word1, string word2) 
{
    int m = word1.length();
    int n = word2.length();

    // Create a table to store the minimum edit distance between substrings of word1 and word2
    //int dp[m + 1][n + 1];
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    // Initialize the table for the base cases
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    // Compute the minimum edit distance for all substrings of word1 and word2
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) 
            {
                // Last characters match, no operation required
                dp[i][j] = dp[i - 1][j - 1];
            }
            else 
            {
                // Insert a character into word1
                int insertOp = dp[i][j - 1];
                // Delete a character from word1
                int deleteOp = dp[i - 1][j];
                // Replace a character in word1 with a character in word2
                int replaceOp = dp[i - 1][j - 1];
                // Take the minimum of the three operations and add 1
                dp[i][j] = 1 + min(min(insertOp, deleteOp), replaceOp);
            }
        }
    }
    // Return the minimum edit distance between the entire strings
    return dp[m][n];
}


int main()
{
    //string word1 = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdef";
    //string word2 = "bcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefg";
    string word1 = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz", word2 = "bcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyza";
    //int res = minDistance(word1, word2);
    int res = minDistanceBetter(word1, word2);
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
