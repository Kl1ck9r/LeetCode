/*
    Given the root of a binary tree, determine if it is a valid binary search tree (BST).

    A valid BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
*/



//  #1
class Solution {
public:
    void inorder(TreeNode *node){
      if(node->left) inorder(node->left);
       m_vec.push_back(node->val);
       if(node->right) inorder(node->right);
    }

    bool isValidBST(TreeNode* root) {
        inorder(root);

      for(int i = 0;i<m_vec.size() - 1;i++) {
         if(m_vec[i]>=m_vec[i+1]) {
             return false;
           }
        }
       return true;
    }

private:
    vector<int> m_vec;
};
