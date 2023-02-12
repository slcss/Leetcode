// Leetcode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;




 struct ListNode 
 {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; 


 ListNode* listCreate(vector<int>& v)
 {
     ListNode* p = nullptr, * t = nullptr;
     for (auto vi : v)
     {
         //int a = 1;
         //int* pa = &a;

         ListNode *node = new ListNode(vi);
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

 void printList(ListNode* l)
 {
     while (l != nullptr)
     {
         cout << l->val << " ";
         l = l->next;
     }
     cout << endl;
 }

 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
 {
     ListNode* l1_temp = l1, * l2_temp = l2;
     ListNode* sum = new ListNode();
     ListNode* psum = sum;
     //ListNode *psum;
     int num = 0;

     while (l1_temp != nullptr || l2_temp != nullptr || num != 0)
     {
         int l1_val = 0, l2_val = 0;
         if (l1_temp != nullptr)
         {
             l1_val = l1_temp->val;
             l1_temp = l1_temp->next;
         }
         if (l2_temp != nullptr)
         {
             l2_val = l2_temp->val;
             l2_temp = l2_temp->next;
         }
         psum->val = (l1_val + l2_val + num) % 10;
         num = (l1_val + l2_val + num) / 10;

         if (l1_temp != nullptr || l2_temp != nullptr || num != 0)
         {
             ListNode *sum_node = new ListNode();
             psum->next = sum_node;
             psum = sum_node;
         }
     }

     return sum;
 }

int main()
{
    //vector<int> v1 = { 2,4,3 }, v2 = { 5,6,4 };
    //vector<int> v1 = { 0 }, v2 = { 0 };
    vector<int> v1 = { 9,9,9,9,9,9,9 }, v2 = { 9,9,9,9 };

    ListNode* l1 = listCreate(v1);
    ListNode* l2 = listCreate(v2);
    printList(l1);
    printList(l2);

    ListNode* sum = addTwoNumbers(l1, l2);
    printList(sum);



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
