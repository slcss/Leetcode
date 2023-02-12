// Leetcode22.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace::std;

vector<string> comb;


//backtracking method
void recursive(string &cur, int frontNum, int backNum)
{
    
    if (!frontNum && !backNum)
    {
        //cout << cur << endl;
        comb.push_back(cur);
        return;
    }        

    if (frontNum == backNum)
    {
        cur += "(";  
        cout << cur << endl;
        recursive(cur, frontNum - 1, backNum);
    }
    else
    {
        if (!frontNum)
        {
            cur += ")";
            cout << cur << endl;
            recursive(cur, frontNum, backNum - 1);
        }
        else
        {
            string temp = cur;
            //cur += "(";
            //cout << cur << endl;
            //recursive(cur, frontNum - 1, backNum);
            string a = temp + "(";
            cout << a << endl;
            recursive(a, frontNum - 1, backNum);    //although use a instead of cur,lose the bond to outside string a ,but it still works
            //cur = temp + ")";
            //cout << cur << endl;
            //recursive(cur, frontNum, backNum - 1);
            a = temp + ")";
            cout << a << endl;
            recursive(a, frontNum, backNum - 1);
        }   
    }
}


vector<string> generateParenthesis(int n) 
{
    int frontNum = n, backNum = n;

    string a = "";

    recursive(a, frontNum, backNum);

    return comb;
    
}

int main()
{
    int n = 4;
   

    generateParenthesis(n);

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
