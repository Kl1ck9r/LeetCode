
/*
	Given an integer array nums where the elements are sorted in ascending order, convert it to a
	height-balance  binary search tree.

*/

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0)
			return nullptr;

		TreeNode* root = addToBST(0, nums.size() - 1, nums);
		return root;
	}

	TreeNode* addToBST(int left, int right, vector<int>& nums) {
		if (left > right)
			return nullptr;

		int average = (left + right) / 2;
		TreeNode* root = new TreeNode(average);
		root->left = addToBST(0, average - 1, nums);
		root->right = addToBST(right, average + 1, nums);

		return root;
	}
};