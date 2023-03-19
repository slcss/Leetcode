// Leetcode121.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int maxProfit(vector<int>& prices) {
    int profit = 0;
    int buyDay = -1;
    int sellDay = -1;

    for (int i = 0; i < prices.size(); ++i)
    {
        if (buyDay == -1)
            buyDay = i;
        else
        {
            if (prices[i] < prices[buyDay])
            {
                if (sellDay != -1)
                    profit = max(profit, prices[sellDay] - prices[buyDay]);
                buyDay = i;
                sellDay = -1;
            }
            else if (sellDay == -1 || prices[i] > prices[sellDay])
                sellDay = i;
        }
    }
    if (sellDay != -1) profit = max(profit, prices[sellDay] - prices[buyDay]);
    return profit;
}

int maxProfit(vector<int>& prices) {
    int lsf = INT_MAX;
    int op = 0;
    int pist = 0;

    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < lsf) {
            lsf = prices[i];
        }
        pist = prices[i] - lsf;
        if (op < pist) {
            op = pist;
        }
    }
    return op;
}

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
