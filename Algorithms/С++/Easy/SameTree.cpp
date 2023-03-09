
/*

Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

*/

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q != nullptr)
			return false;

		else if (q == nullptr && p != nullptr)
			return false;

		else if (p == nullptr && q == nullptr)
			return true;

		bool tr = false;
		bool fl = false;

		if (p->val == q->val) {
			tr = isSameTree(p->right, q->right);
			fl = isSameTree(p->left, q->left);
		}

		return  fl && tr;
	}
};