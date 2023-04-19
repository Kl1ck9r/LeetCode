
/*
	Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf
	path such that adding up all the values along the path equals targetSum.
	A leaf is a node with no children
*/

class Solution {
public:
	bool hasPathSum(TreeNode* root, int targetSum) {
		if (!root)
			return false;

		int sum = 0;
		sum -= root->data;
		if (!root->left && !root->right && sum == targetSum)
			return true;

		if (root->left)
			hasPathSum(root->left, targetSum);

		if (root->right)
			hasPathSum(root->right, targetSum);

		return false;
	}

};
