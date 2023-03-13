/*

	Given the root of a binary tree, return the sum of all left leaves.
	A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

*/

class Solution {
private:
	int sum = 0;
public:

	int sumOfLeftLeaves(TreeNode* root) {
		if (root == nullptr)
			return 0;

		if (root->left != nullptr && !root->left->left && !root->left->right) {
			sum += root->left->val;
		}

		sumOfLeftLeaves(root->left);
		sumOfLeftLeaves(root->right);

		return sum;
	}
};