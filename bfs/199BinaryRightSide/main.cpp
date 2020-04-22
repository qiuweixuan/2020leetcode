
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<iostream>
#include<vector>
#include<queue>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution
{
public:
    std::vector<int> rightSideView(TreeNode *root)
    {
        queue< pair<TreeNode *,int> > nodeLevel;
        vector<int> ans;
        if(!root){
            return ans;
        }
        nodeLevel.push(make_pair(root,0));
        int level = -1;

        while(!nodeLevel.empty()){
            auto p = nodeLevel.front();
            TreeNode* node = p.first;
            int curLevel = p.second;
            nodeLevel.pop();

            if(curLevel > level){
                level = curLevel;
                ans.push_back(node->val);
            }
            else{
                ans[level] = node->val;
            }

            if(node->left){
                nodeLevel.push(make_pair(node->left,curLevel+1));
            }
            if(node->right){
                nodeLevel.push(make_pair(node->right,curLevel+1));
            }
        }

        return ans;
    }
};