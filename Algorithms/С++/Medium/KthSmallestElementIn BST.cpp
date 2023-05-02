    /*
        Given the root of a binary search tree, and an integer k,
        return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
    */


// #1
class Solution {
public:
    void toVector(TreeNode *node,std::vector<int> &vec) {
        if(node == nullptr) { return ;}
        toVector(node->left,vec);
        vec.push_back(node->val);
        toVector(node->right,vec);
    }

    int kthSmallest(TreeNode* root, int k) {
        std::vector<int> nums;
        toVector(root,nums);
        if(nums.size() < k) {
            return -1;
        }

        return nums[k-1];
    }
};
