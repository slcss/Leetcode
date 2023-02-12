// Leetcode19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace::std;

struct ListNode {
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

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    vector<ListNode*> pNode;

    ListNode* temp = head;
    while (temp)
    {
        pNode.push_back(temp); 
        temp = temp->next;
    }

    if (0 == pNode.size() - n)
    {
        head = head->next;
    }
    else
    {
        pNode[pNode.size() - n - 1]->next = pNode[pNode.size() - n]->next;
    }

    return head;
}

ListNode* removeNthFromEndBetter(ListNode* head, int n)
{
    ListNode* first = head, * second = head;

    int i;
    for (i = 0; i < n; ++i)
    {
        if (!first->next)
            break;
        first = first->next;
    }
    if (i != n)
    {
        head = head->next;
        return head;
    }

    while (first->next)
    {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;


    return head;
}

int main()
{
    vector<int> data = { 1};
    int n = 1;

    ListNode* head = listCreate(data);

    //head = removeNthFromEnd(head, n); 
    head = removeNthFromEndBetter(head, n);
    

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
