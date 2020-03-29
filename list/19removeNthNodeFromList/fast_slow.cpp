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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;

        unique_ptr<ListNode> dummy(new ListNode(-1));
        dummy->next = head;
        ListNode* slow = dummy.get();

        while(fast&&n--){
            fast = fast->next;
        }
    
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* del = slow->next;
        slow->next = del->next;
        delete del;
        
        
        return dummy->next;
    }
};