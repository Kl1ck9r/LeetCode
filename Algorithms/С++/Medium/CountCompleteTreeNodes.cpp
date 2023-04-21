/*

Given the root of a complete binary tree, return the number of the nodes in the tree.
According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree,
and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
Design an algorithm that runs in less than O(n) time complexity.

*/

class Solution {
public:
	int countNodes(TreeNode* root) {
		if (!root)
			return 0;
		vector<int> vec;
		addToVector(root, vec);
		return vec.size();
	}

	void addToVector(TreeNode* root, vector<int>& answ) {
		answ.push_back(root->val);
		if (root->left)   addToVector(root->left, answ);
		if (root->right)  addToVector(root->right, answ);
	}
}


//#2 
class Solution {
public:
	int countNodes(TreeNode* root) {
		if (!root)
			return 0;
		return 1 + countNodes(root->left) + countNodes(root->right);
	}
};