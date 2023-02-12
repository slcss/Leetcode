// Leetcode24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace::std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* listCreate(vector<int>& v)
{
    ListNode* p = nullptr, * t = nullptr;
    for (auto vi : v)
    {
        //int a = 1;
        //int* pa = &a;

        ListNode* node = new ListNode(vi);
        //ListNode node = ListNode(vi);

        if (p == nullptr)
            p = node;
        if (t == nullptr)
            t = node;
        else
        {
            t->next = node;
            t = node;
        }
    }
    return p;
}


ListNode* swapPairs(ListNode* head)
{
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
        return head;


    ListNode* begin = head, * tail = nullptr, * leftBegin = head;
    begin = head->next;


    ListNode* temp = nullptr;
    while (leftBegin->next != nullptr)
    {
        ListNode* leftBegin2 = leftBegin->next;
        temp = leftBegin2->next;
        leftBegin2->next = leftBegin;
        leftBegin->next = temp;
        if(tail)
            tail->next = leftBegin2;
        tail = leftBegin;
        leftBegin = temp;
        if (tail->next == nullptr)
            break;
    }
    tail->next = leftBegin;


    return begin;

}

int main()
{
    vector<int> vi = { 1,2,3,4,5 };
    ListNode* pl = listCreate(vi);

    ListNode* res = swapPairs(pl);

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
