    /*
        Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree,
        and every node has no left child and only one right child.
    */



class Solution {
public:
    TreeNode *toBST(std::vector<int>&vec) {
        if(vec.empty()) {
            return nullptr;
        }

        TreeNode *n_root = new TreeNode(vec[0]);
        for(size_t i = 1;i<vec.size();++i) {

        TreeNode *curr = n_root;
        while(curr) {
            if(curr->val>vec[i]) {
                if(curr->left == nullptr) {
                    curr->left = new TreeNode(vec[i]);
                     break;
                } else {
                    curr = curr->left;
                }

            } else if(curr->val<vec[i]) {
                if(curr->right == nullptr) {
                    curr->right=  new TreeNode(vec[i]);
                    break;
                } else {
                    curr = curr->right;
                }
            }
        }
    }

        return n_root;
    }

    TreeNode* increasingBST(TreeNode* root) {
        if(root == nullptr)  {
            return root;
        }

        vector<int> temp;
        TreeNode*curr = root;
        std::stack<TreeNode*> st;

        while(curr!=nullptr || !st.empty()) {
            while(curr!=nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            temp.push_back(curr->val);
            curr = curr->right;
        }

        TreeNode *new_node = toBST(temp);
        return new_node;
    }
};
