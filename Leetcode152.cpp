// Leetcode152.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace::std;


int maxProduct(vector<int>& nums) {
    long maxP = 0;

    if (nums.size() == 1) return nums[0];

    vector<int> data;
    long product = 0;
    int negNum = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != 0)
        {
            if (nums[i] > 0) product = product == 0 ? nums[i] : product * nums[i];
            if (nums[i] < 0)
            {
                if (product > 0)
                {
                    data.push_back(product);
                    product = 0;
                }
                data.push_back(nums[i]);
                ++negNum;
            }
        }
        if(nums[i] == 0 || i== nums.size()-1)
        {
            if (product > 0) data.push_back(product);
            if (negNum % 2 == 0)
            {
                long product = 0;
                for (auto num : data)
                    product = product == 0 ? num : product * num;
                maxP = max(maxP, product);
            }
            else
            {
                if (negNum == 1)
                {
                    long product = 0;
                    for (auto num : data)
                    {
                        if (num > 0) product = product == 0 ? num : product * num;
                        else
                        {
                            maxP = max(maxP, product);
                            product = 0;
                        }
                    }
                    maxP = max(maxP, product);
                }
                else
                {
                    int firstIndex = 0, lastIndex = 0;
                    long  p1 = 1, p2 = 1, p3 = 1;
                    for (int i = 0; i < data.size(); ++i)
                    {
                        if (data[i] < 0) { firstIndex = i; break; }
                    }
                    for (int i = data.size()-1; i >= 0; --i)
                    {
                        if (data[i] < 0) { lastIndex = i; break; }
                    }
                    for (int i = 0; i <= firstIndex; ++i) p1 *= data[i];
                    for (int i = firstIndex + 1; i <= lastIndex - 1; ++i) p2 *= data[i];
                    for (int i = lastIndex; i < data.size(); ++i) p3 *= data[i];
                    maxP = max(maxP, max(p1 * p2, p2 * p3));
                }
            }
            data.clear();
            product = 0;
            negNum = 0;

        }
        
    }
    return maxP;
}

int maxProduct(vector<int>& nums) 
{
    int maxi = INT_MIN;
    int prod = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        prod *= nums[i];
        maxi = max(prod, maxi);
        if (prod == 0)
            prod = 1;
    }
    prod = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        prod *= nums[i];

        maxi = max(prod, maxi);
        if (prod == 0)
            prod = 1;
    }
    return maxi;
}

int main()
{
    vector<int> nums = { 0,-2,0 };
    int res = maxProduct(nums);

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
