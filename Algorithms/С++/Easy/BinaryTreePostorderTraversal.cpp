/*
	Given the root of a binary tree, return the postorder traversal of its nodes' values.
*/

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root)
	{
		if (!root)
			return {};
		vector<int> result;
		addToVector(root, result);
		return result;
	}

	void addToVector(TreeNode* node, vector<int>& vec) {

		if (node->left)
			addToVector(node->left, vec);
		if (node->right)
			addToVector(node->right, vec);

		vec.push_back(node->val);
	}
};