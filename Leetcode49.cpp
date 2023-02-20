// Leetcode49.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <unordered_map>
#include <algorithm>

using namespace::std;


bool checkAnagram(string& s1, string& s2)
{
    array<int, 26> arr1{ 0 }, arr2{ 0 };

    for (auto& ch : s1)
        ++arr1[ch - 'a'];
    for (auto& ch : s2)
        ++arr2[ch - 'a'];

    return arr1 == arr2;

}

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    vector<vector<string>> anagrams;
    if (strs.empty())
    {
        anagrams.push_back(strs);
        return anagrams;
    }

    for (auto& str : strs)
    {
        if (anagrams.empty())
        {
            anagrams.push_back(vector<string>{str});
            continue;
        }

        int flag = 0;
        for (auto& anagram : anagrams)
        {
            if (anagram[0].size() != str.size())
                continue;
            if (checkAnagram(anagram[0], str))
            {
                anagram.push_back(str);
                flag = 1;
                break;
            }
        }
        if(!flag)
            anagrams.push_back(vector<string>{str});
    }

    return anagrams;
}

vector<vector<string>> groupAnagramsBetter(vector<string>& strs)
{
    vector<vector<string>> anagrams;
    unordered_map<string, vector<string>> mapAnagrams;

    for (auto str : strs)
    {
        string s = str;
        sort(str.begin(), str.end());
        mapAnagrams[str].push_back(s);
    }

    for (auto &mapAnagram : mapAnagrams)
    {
        anagrams.push_back(mapAnagram.second);
    }

    return anagrams;
}

int main()
{
    //vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
    //vector<vector<string>> anagrams = groupAnagrams(strs);

    vector<string> strs = { "" };
    vector<vector<string>> anagrams = groupAnagramsBetter(strs);

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
