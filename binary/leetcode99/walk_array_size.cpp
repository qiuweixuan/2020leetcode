#include <vector>
#include <map>
using namespace std;

struct TreeNode
{
    /* data */
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val{v}, left{NULL}, right{NULL} {}
};

// 原本有序的二叉搜索树变得无序
// 中序遍历所得的升序数组，出现逆序对
// 因为原本是升序，交换过后必定是大元素在前，小元素在后
// 大元素在前:第一个逆序相邻对的左元素
// 小元素在后:最后一个逆序相邻对的右元素

class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> orderTree;
        walk(root,orderTree);

        TreeNode* firstReverse = nullptr;
        TreeNode* finalReverse = nullptr;

        for (size_t i = 1; i < orderTree.size(); i++)
        {
            if(orderTree[i - 1]->val > orderTree[i]->val){
                firstReverse = orderTree[i - 1];
                break;
            }
        }

        for (size_t i = orderTree.size() - 1; i > 0 ; i--)
        {
            if(orderTree[i - 1]->val > orderTree[i]->val){
                finalReverse = orderTree[i];
                break;
            }
        }
        swap(firstReverse->val,finalReverse->val);
    }

    void walk(TreeNode* root,vector<TreeNode*>& orderTree){
        if(!root){
            return;
        }
        walk(root->left,orderTree);
        orderTree.emplace_back(root);
        walk(root->right,orderTree);
    }
};