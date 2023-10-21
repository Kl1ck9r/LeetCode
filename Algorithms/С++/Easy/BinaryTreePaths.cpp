/*
    Given the root of a binary tree, return all root-to-leaf paths in any order.
    A leaf is a node with no children.

    Example 1:

    Input: root = [1,2,3,null,5]
    Output: ["1->2->5","1->3"]
    Example 2:

    Input: root = [1]
    Output: ["1"]
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<string> currentPath;
        dfs(root,result,currentPath);
        return result;
    }

    void dfs(TreeNode *node,vector<string> &result,vector<string> currentPath) {
        if(!node) return;

        currentPath.emplace_back(to_string(node->val));

        if(!node->left && !node->right) {
            string path = currentPath.front();
            for (int i = 1; i < currentPath.size(); ++i)
                path += "->" + currentPath[i];
            result.emplace_back(path);
        }

        dfs(node->left,result,currentPath);
        dfs(node->right,result,currentPath);

        currentPath.pop_back();
    }
};
