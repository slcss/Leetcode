// Leetcode21.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
    if (list1 == nullptr)
        return list2;
    if (list2 == nullptr)
        return list1;

    ListNode* head = nullptr, * headTmp = nullptr;
    ListNode* temp1 = list1, * temp2 = list2;

    if (list1->val <= list2->val)
    {
        head = list1;
        headTmp = list1;
        temp1 = temp1->next;
    }  
    else
    {
        head = list2;
        headTmp = list2;
        temp2 = temp2->next;
    }

    while (temp1 != nullptr || temp2 != nullptr)
    {
        int val1, val2;
        if (temp1 == nullptr)      
            val1 = 120;        
        else
            val1 = temp1->val;
        if (temp2 == nullptr)
            val2 = 120;
        else
            val2 = temp2->val;

        if (val1 <= val2)
        {
            headTmp->next = temp1;
            headTmp = headTmp->next;
            temp1 = temp1->next;
        }
        else
        {
            headTmp->next = temp2;
            headTmp = headTmp->next;
            temp2 = temp2->next;
        }

    }

    return head;
   
}

int main()
{
    vector<int> vi1 = {  };
    vector<int> vi2 = {1 };

    ListNode* pl1 = listCreate(vi1);
    ListNode* pl2 = listCreate(vi2);

    ListNode* res = mergeTwoLists(pl1, pl2);


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
