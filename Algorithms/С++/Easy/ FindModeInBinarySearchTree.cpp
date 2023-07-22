    /*
        Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.
        If the tree has more than one mode, return them in any order.
        Assume a BST is defined as follows:
        The left subtree of a node contains only nodes with keys less than or equal to the node's key.
        The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
        Both the left and right subtrees must also be binary search trees.
    */



class Solution {
public:
    void toUnorderMap(TreeNode*node,std::unordered_map<int,int>&mp) {
        if(node == nullptr) {
            return;
        }
        toUnorderMap(node->left,mp);
        mp[node->val]++;
        toUnorderMap(node->right,mp);
    }

    vector<int> findMode(TreeNode* root) {
        if(root == nullptr){
            return {};
        }

        unordered_map<int,int> mp;
        vector<int> result{};
        toUnorderMap(root,mp);

        int maxCount = 0;
        for(const auto& it : mp) {
        if(it.second > maxCount) {
            maxCount = it.second;
            result = {it.first};
        } else if(it.second == maxCount) {
            result.push_back(it.first);
        }
    }

     return result;
    }
};
