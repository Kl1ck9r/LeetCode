    /*
        Given the root of a binary search tree and an integer k,
        return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
    */




class Solution {
public:
    bool helperFind(TreeNode *root,int k,unordered_map<int,int>&mp) {
        if(root==nullptr) {
           return false;
        }

        if(mp.find(k-root->val)!=mp.end()) {
            return true;
        }

        mp[root->val] = root->val;
        return helperFind(root->left,k,mp) || helperFind(root->right,k,mp);
    }

    bool findTarget(TreeNode* root, int k) {
      unordered_map<int,int>mp;
      return helperFind(root,k,mp);
    }
};
