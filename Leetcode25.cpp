// Leetcode25.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

ListNode* reverseKGroup(ListNode* head, int k) 
{
    ListNode* temp = head;
    for (int i = 1; i <= k; ++i)
    {
        if (temp == nullptr)
            return head;
        else
            temp = temp->next;
    }

    ListNode* tempHead = head, * tempTail = head;
    ListNode* tmpAfter = nullptr, * tmpBefore = nullptr;
    for (int i = 1; i <= k; ++i)
    {
        tmpAfter = tempHead->next;
        tempHead->next = tmpBefore;

        tmpBefore = tempHead;
        tempHead = tmpAfter;
    }

    head->next = reverseKGroup(tempHead, k);

    return tmpBefore;
}

int main()
{
    vector<int> vi = { 1,2,3,4,5 };
    int k = 3;
    ListNode* pl = listCreate(vi);

    ListNode* res = reverseKGroup(pl, k);
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
