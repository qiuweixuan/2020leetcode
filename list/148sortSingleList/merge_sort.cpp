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

class Solution
{
public:
    //向下整除中点
    ListNode* getMidOfList(ListNode *head)
    {
        ListNode *fast_ptr = head->next;
        ListNode *slow_ptr = head;
        while (fast_ptr && fast_ptr->next)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        return slow_ptr;
    }

    ListNode *sortList(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        
        ListNode *left_tail = getMidOfList(head);
        ListNode *right_head = left_tail->next;
        left_tail->next = NULL;

        unique_ptr<ListNode> ans_head(new ListNode(-1));
        ListNode *merge_ptr = ans_head.get();

        //子任务排序
        ListNode *left_ptr = sortList(head);
        ListNode *right_ptr = sortList(right_head);

        //归并
        while (left_ptr && right_ptr)
        {
            if (left_ptr->val <= right_ptr->val)
            {
                merge_ptr->next = left_ptr;
                left_ptr = left_ptr->next;
            }
            else
            {
                merge_ptr->next = right_ptr;
                right_ptr = right_ptr->next;
            }
            merge_ptr = merge_ptr->next;
        }

        merge_ptr->next = left_ptr != NULL?left_ptr:right_ptr;

        return ans_head->next;
    }

};



void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        
        ListNode* ret = Solution().sortList(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}