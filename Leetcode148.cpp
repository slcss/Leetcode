// Leetcode148.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* temp = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = nullptr;

        ListNode* list1 = sortList(head);
        ListNode* list2 = sortList(slow);

        return merge(list1, list2);

    }

    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        ListNode* realHead = nullptr;
        ListNode* tail = nullptr;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                if (realHead == nullptr)
                {
                    realHead = tail = list1;
                }
                else
                {
                    tail->next = list1;
                    tail = tail->next;
                }
                list1 = list1->next;

            }
            else
            {
                if (realHead == nullptr)
                {
                    realHead = tail = list2;
                }
                else
                {
                    tail->next = list2;
                    tail = tail->next;
                }
                list2 = list2->next;
            }
        }
        if (list1 != nullptr) tail->next = list1;
        if (list2 != nullptr) tail->next = list2;

        return realHead;
    }
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
