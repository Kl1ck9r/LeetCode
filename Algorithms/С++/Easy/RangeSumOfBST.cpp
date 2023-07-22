    /*
        Given the root node of a binary search tree and two integers low and high,
        return the sum of values of all nodes with a value in the inclusive range [low, high].
    */



// #1
class Solution {
public:
    void toVector(TreeNode *node,std::vector<int> &vec) {
        vec.push_back(node->val);
        toVector(node->left,vec);
        toVector(node->right,vec);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr) {
            return -1;
        }

        int sum = 0;
        vector<int> vec;
        vector<int> output;

        toVector(root,vec);
        copy_if(vec.begin(),vec.end(),back_inserter(output),[=](int x ) { return x >= 7 && x <= 15;});

        for(const auto it : output){
           sum+=it;
        }

        return sum;
    }
};

//#2
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
      if(root == nullptr)  {
         return 0;
      }

      std::stack<TreeNode*> n_st;
      std::stack<int>st;
      TreeNode *node = root;
      int sum = 0;

      while(node!=nullptr || !n_st.empty()) {
        while(node) {
            n_st.push(node);
            node = node->left;
        }

        node = n_st.top();
        n_st.pop();

        if(node->val >= low && node->val <= high){
            st.push(node->val);
        }

        node = node->right;
      }

      while(!st.empty()){
        sum+=st.top();
        st.pop();
      }

      return sum;
    }
};
