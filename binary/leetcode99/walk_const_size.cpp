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

        TreeNode* prev = nullptr;
        TreeNode* post = nullptr;

        TreeNode* firstReverse = walk_firstRev(root,prev);
        TreeNode* finalReverse = walk_finalRev(root,post);

        
        swap(firstReverse->val,finalReverse->val);
    }

    TreeNode* walk_firstRev(TreeNode* root,TreeNode* &prev){
        if(!root){
            return NULL;
        }
        
        TreeNode* firstReverse =  walk_firstRev(root->left,prev);
        if(firstReverse){
            return firstReverse;
        }

        if(prev && prev->val > root->val){
            firstReverse = prev;
           
        }
        else{
            prev = root;
            firstReverse = walk_firstRev(root->right,prev);
        }
        return firstReverse;   
    }


     TreeNode* walk_finalRev(TreeNode* root,TreeNode* &post){
        if(!root){
            return NULL;
        }
        
        TreeNode* finalReverse =  walk_finalRev(root->right,post);
        if(finalReverse){
            return finalReverse;
        }

        if(post && post->val < root->val){
            finalReverse = post;
        }
        else{
            post = root;
            finalReverse = walk_finalRev(root->left,post);
        }
        return finalReverse;   
    }
};