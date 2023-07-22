/*

	Given a root node reference of a BST and a key, delete the node with the given key in the BST.
	Return the root node reference (possibly updated) of the BST.
	Basically, the deletion can be divided into two stages:
	Search for a node to remove.
	If the node is found, delete the node.

*/

class Solution {
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (!root)
			return nullptr;

		if (root->val < key) {
			root->right = deleteNode(root->right, key);
		}
		else if (root->val > key) {
			root->left = deleteNode(root->left, key);
		}
		else {
			if (root->left == nullptr) {
				return root->right;
			}
			else if (root->right == nullptr) {
				return root->left;
			}
			else {
				TreeNode* temp = root->right;
				while (temp->left != nullptr) {
					temp = temp->left;
				}
				root->val = temp->val;
				root->right = deleteNode(root->right, temp->val);
			}
		}
		return root;
	}
};
