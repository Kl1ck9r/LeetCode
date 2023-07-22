    /*
        Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
        For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
        Two binary trees are considered leaf-similar if their leaf value sequence is the same.
        Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar
    */


class Solution {
public:
    void toVector(TreeNode* root, std::vector<int>& vec) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            vec.push_back(root->val);
            return;
        }

        toVector(root->left, vec);
        toVector(root->right, vec);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> vec_t1{}, vec_t2{};

        toVector(root1, vec_t1);
        toVector(root2, vec_t2);

        return vec_t1 == vec_t2;
    }
};
