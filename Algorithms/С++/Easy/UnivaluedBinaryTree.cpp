/*
* 
	A binary tree is uni-valued if every node in the tree has the same value.
	Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.

*/


class Solution {
public:
	bool isUnivalTree(TreeNode* root) {
		if (!root)
			return false;

		auto t_if = !root->left || root->left->val == root->val && isUnivalTree(root->left);
		auto t2_if = !root->right || root->right->val == root->val && isUnivalTree(root->right);

		return t_if && t2_if;
	}

};