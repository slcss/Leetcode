// Leetcode155.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


class MinStack {
public:
    MinStack() {
        minNum = INT_MAX;
        cout << "INT_MAX " << INT_MAX << endl;
        cout << "INT_MIN " << INT_MIN << endl;
    }

    void push(int val) {
        nums.push_back(val);
        minNum = min(minNum, val);
        mins.push_back(minNum);
        //cout<<minNum<<" "<<val<<endl;
    }

    void pop() {
        nums.pop_back();
        mins.pop_back();
        minNum = getMin();
        //cout<<"nums size: "<<nums.size()<<" "<<"minNum: "<<minNum<<endl;
    }

    int top() {
        return nums.back();
    }

    int getMin() {
        if (!nums.size()) return INT_MAX;
        return mins.back();
    }

    list<int> nums;
    list<int> mins;
    int minNum;

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
