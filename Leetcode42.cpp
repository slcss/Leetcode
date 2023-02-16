// Leetcode42.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace::std;

int trap(vector<int>& height)
{
    int sum = 0;
    int lastHeight = INT_MAX;

    vector<int> newHeight(height);

    vector<int> boundry;
    vector<int> index;

    for (int i = 0; i < height.size(); ++i)
    {
        if (!height[i])
            continue;

        if (height[i] < lastHeight)
        {
            boundry.push_back(height[i]);
            index.push_back(i);
        }
        else
        {
            while (!boundry.empty())
            {
                int bback = boundry.back();
                int iback = index.back();
                if (height[i] < bback)
                {
                    for (int j = iback + 1; j < i; ++j)
                    {
                        newHeight[j] = height[i];
                    }
                    break;
                }
                else
                {
                    for (int j = iback + 1; j < i; ++j)
                    {
                        newHeight[j] = bback;
                    }
                    boundry.pop_back();
                    index.pop_back();
                }
            }
            boundry.push_back(height[i]);
            index.push_back(i);
        }
        lastHeight = height[i];
    }

    for (int i = 0; i < height.size(); ++i)
    {
        cout << height[i] << " ";
        sum += newHeight[i] - height[i];
    }
    cout << endl;
    for (int i = 0; i < height.size(); ++i)
    {
        cout << newHeight[i] << " ";
    }
    cout << endl;
    /*for(int i=0;i<height.size();++i)
    {
        sum+=newHeight[i]-height[i];
    }*/

    return sum;
}

int main()
{
    vector<int> height = { 9,8,9,5,8,8,8,0,4 };
    int sum = trap(height);

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
