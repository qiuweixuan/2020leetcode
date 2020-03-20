/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

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

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int tree_size = inorder.size();
        map<int, int> val_to_inorderID;
        for (int i = 0; i < tree_size; i++)
        {
            int val = inorder[i];
            //反向映射
            val_to_inorderID[val] = i;
        }

        //确定区间边界
        int pre_start, pre_end, in_start, in_end;
        pre_start = in_start = 0;
        pre_end = in_end = tree_size;

        return buildTree(preorder,pre_start,pre_end,
                         inorder,in_start,in_end,
                        val_to_inorderID);
    }

    TreeNode *buildTree(vector<int> &preorder, int pre_start, int pre_end,
                        vector<int> &inorder, int in_start, int in_end,
                        map<int,int>& val_to_inorderID)
    {
        //递归边界条件
        if(pre_start >= pre_end || in_start >= in_end){
            return NULL;
        }

        //确定根值
        int root_val = preorder[pre_start];
        TreeNode* root = new TreeNode(root_val);
        //确定中序分界点
        int in_mid = val_to_inorderID[root_val];
        int left_size = in_mid - in_start;
        //确定前序分界点
        int pre_mid = pre_start + 1 +left_size;

    
        root->left = buildTree(preorder,pre_start + 1,pre_mid,
                    inorder,in_start,in_mid,
                        val_to_inorderID);

        root->right = buildTree(preorder,pre_mid,pre_end,
                    inorder,in_mid + 1, in_end,
                        val_to_inorderID);

        return root;
    }
};