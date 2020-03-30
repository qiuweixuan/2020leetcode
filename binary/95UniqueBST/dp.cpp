#include <vector>
#include <map>
using namespace std;

class TreeNode
{
public:
    /* data */
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val{v}, left{NULL}, right{NULL} {}
};

class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        return generate_child_trees(1,n);
    }

    vector<TreeNode *> generate_child_trees(int start, int end)
    {
        vector<TreeNode *> all_trees;
        if (start > end)
        {
            all_trees.push_back(NULL);
            return all_trees;
        }

        //选择根
        for (int i = start; i <= end; i++)
        {
            //后序遍历

            auto left_trees = generate_child_trees(start, i - 1);
            auto right_trees = generate_child_trees(i + 1, end);
            for (auto l : left_trees)
            {
                for (auto r : right_trees)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    all_trees.push_back(root);
                }
            }
        }
        return all_trees;
    }
};