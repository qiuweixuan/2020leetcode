#include<iostream>
#include<algorithm>
#include<sstream> 
#include<string>
#include<memory>
#include<vector>
#include<list>
using namespace std;


class ListNode{
    public:
        int val;
        ListNode* next;
        ListNode(int x):val{x},next{NULL} {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
       
        if(!head){
            return NULL;
        }
        
        //划分点元素
        int pivot = head->val;
        //小于pivot
        unique_ptr<ListNode> left_head(new ListNode(-1));
        ListNode* left_tail = left_head.get();

        //大于pivot
        unique_ptr<ListNode> right_head(new ListNode(-1));
        ListNode* right_tail = right_head.get();

        //等于pivot
        unique_ptr<ListNode> mid_head(new ListNode(-1));
        ListNode* mid_tail = mid_head.get();

        
        //进行划分,分为小于，大于，等于
        for(auto it = head;it;it = it->next){
            if(it->val < pivot){
                left_tail->next = it;
                left_tail = left_tail->next;
            }
            else if(it->val > pivot){
                right_tail->next = it;
                right_tail = right_tail->next;
            }
            else{
                mid_tail->next = it;
                mid_tail = mid_tail->next;
            }
        }
        
        left_tail->next = NULL;
        mid_tail->next = NULL;
        right_tail->next = NULL;

        //递归子任务排序
        left_head->next = sortList(left_head->next);
        right_head->next = sortList(right_head->next);

        //串联起各个块
        getTail(left_head.get())->next = mid_head->next;
        getTail(left_head.get())->next = right_head->next;
        
        return left_head->next;
    }

    ListNode* getTail(ListNode*head){
        while(head->next){
            head = head->next;
        }
        return head;
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