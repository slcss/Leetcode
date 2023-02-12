// Leetcode3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace::std;

int lengthOfLongestSubstring(string s)
{
    int maxLength = 0;

    for (auto it = s.begin(); it != s.end(); ++it)
    {
        unordered_map<char, int> mp;
        for (auto it1 = it; it1 != s.end(); ++it1)
        {
            if (mp.find(*it1) == mp.end())
                mp[*it1] = 1;
            else
                break;
        }
        if (mp.size() > maxLength)
        {
            maxLength = mp.size();
            if (maxLength == s.size())
                break;
        }
            
    }

    return maxLength;
}

int lengthOfLongestSubstringBetter(string s)
{
    unordered_map<char, int> mp;
    auto ibegin = s.begin();
    auto iend = s.begin();

    int maxLength = 0;

    while (iend != s.end())
    {
        mp[*iend] += 1;

        while (mp[*iend] > 1)
        {
            mp[*ibegin] -= 1;
            ++ibegin;
        }
        ++iend;

        maxLength = max(maxLength, static_cast<int>(iend - ibegin));

    }

    return maxLength;
}

int lengthOfLongestSubstringBest(string s)
{
    unordered_map<char, int> mp;
    auto ibegin = s.begin();
    auto iend = s.begin();

    int maxLength = 0;

    while (iend != s.end())
    {
        if (mp.find(*iend) == mp.end())
        {
            mp[*iend] = static_cast<int>(iend - s.begin());
        }
        else
        {            
            ibegin = ibegin > s.begin() + mp[*iend] + 1 ? ibegin : s.begin() + mp[*iend] + 1;
            mp[*iend] = static_cast<int>(iend - s.begin());
        }
        
        ++iend;

        maxLength = max(maxLength, static_cast<int>(iend - ibegin));

    }

    return maxLength;
}

int main()
{
    std::cout << "Hello World!\n";

    string s = "abcabcc";
    //int length = lengthOfLongestSubstring(s);
    //int length = lengthOfLongestSubstringBetter(s);
    int length = lengthOfLongestSubstringBest(s);

    return 0;
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
