// Leetcode70.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace::std;


/*int climbStairs(int n)
    {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        return climbStairs(n-1)+climbStairs(n-2);
    }*/

    /*int arr[45];
    int climbStairs(int n)
    {
        if(n==1)
        {
            arr[n-1]=1;
            return 1;
        }
        if(n==2)
        {
            arr[n-1]=2;
            return 2;
        }
        if(arr[n-1])
            return arr[n-1];
        return climbStairs(n-1)+climbStairs(n-2);
    }*/

int climbStairs(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    vector<int> v(n);
    v[0] = 1; v[1] = 2;

    for (int i = 2; i < n; ++i)
        v[i] = v[i - 1] + v[i - 2];
    return v[n - 1];
}


int main()
{
    int res = climbStairs(1);
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
