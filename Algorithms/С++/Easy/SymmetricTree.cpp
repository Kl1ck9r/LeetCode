/*
    
    Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

*/


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }

        if (left == nullptr || right == nullptr) {
            return false;
        }

        return left->val == right->val && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};