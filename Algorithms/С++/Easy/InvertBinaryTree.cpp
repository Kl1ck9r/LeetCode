
/*
	Given the root of a binary tree, invert the tree, and return its root.
*/



class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr)
			return nullptr;

		invertTree(root->right);
		invertTree(root->left);

		TreeNode* temp = root->right;
		root->right = root->left;
		root->left = temp;

		return root;
	}
};