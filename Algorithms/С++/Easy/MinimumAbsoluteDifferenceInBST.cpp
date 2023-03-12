/*
	Given the root of a Binary Search Tree (BST), return the minimum absolute difference 
	between the values of any two different nodes in the tree.

	*	Input: root = [4,2,6,1,3]
	*	Output: 1
*/


class Solution {
public:
	int getMinimumDifference(TreeNode* root) {
		if (!root)
			return 0;

		int difference = INT_MAX;

		vector<int> vec;
		addToVector(root, vec);

		for (size_t i = 1; i < vec.size(); i++) {
			difference = std::min(Max, vec[i] - vec[i - 1]);
		}
		return defference;
	}
	// symmetrical tree traversal
	void addToVector(TreeNode* root, vector<int>& vec) {
		if (root == nullptr) return;
		addToVector(root->left, vec);
		vec.push_back(root->val);
		addToVector(root->right, vec);
	}
};