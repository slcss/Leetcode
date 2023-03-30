// Leetcode141.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// bool hasCycle(ListNode *head) {
    //     unordered_set<ListNode*> setList;
    //     ListNode *temp = head;
    //     while(temp!=NULL)
    //     {
    //         if(setList.find(temp)!=setList.end())
    //         {
    //             return true;
    //         }
    //         else
    //             setList.insert(temp);
    //         temp = temp->next;    
    //     }   

    //     return false;

    // }

bool hasCycle(ListNode* head) {
    ListNode* p1 = head;
    ListNode* p2 = NULL;
    if (head != NULL && head->next != NULL)
        p2 = head->next->next;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1 == p2) return true;
        p1 = p1->next;
        if (p2->next != NULL)
            p2 = p2->next->next;
        else
            p2 = NULL;

    }
    return false;

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
