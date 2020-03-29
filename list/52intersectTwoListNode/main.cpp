#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <memory>
#include <vector>
#include <list>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val{x}, next{NULL} {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int aSize = getListSize(headA);
        int bSize = getListSize(headB);

        while (aSize > bSize)
        {
            headA = headA->next;
            aSize--;
        }

        while (aSize < bSize)
        {
            headB = headB->next;
            bSize--;
        }

        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
    int getListSize(ListNode* head){
        int size = 0;
        while(head){
            size++;
            head = head->next;
        }
        return size;
    }
};