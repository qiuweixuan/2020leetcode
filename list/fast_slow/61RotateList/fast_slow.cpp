#include<memory>
using namespace std;

class ListNode{
    public:
        int val;
        ListNode* next;
        ListNode(int x):val{x},next{nullptr} {}
};

class Solution {
public:
    int getLenOfList(ListNode* head){
        int len = 0;
        while (head)
        {
            head = head->next;
            len++;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        int len = getLenOfList(head);
        if(len == 0){
            return head;
        }

        k = k % len;
        if(k == 0){
            return head;
        }
        unique_ptr<ListNode> dummy{new ListNode(-1)};
        dummy->next = head;
        ListNode* fast = dummy.get();
        ListNode* slow = dummy.get();
        for (int i = 0; i < k + 1; i++)
        {
            fast = fast->next;
        }
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* right_head = slow->next;
        slow->next = nullptr;
        ListNode* left_head = dummy->next;
        ListNode* right_tail = right_head;
        while(right_tail->next){
            right_tail = right_tail->next;
        }
        right_tail->next = left_head;

        return right_head;
    }
};