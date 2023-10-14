/*
You are given a non-negative integer array nums. In one operation, you must:
Choose a positive integer x such that x is less than or equal to the smallest non-zero element in nums.
Subtract x from every positive element in nums.
Return the minimum number of operations to make every element in nums equal to 0.

Example 1:

Input: nums = [1,5,0,3,5]
Output: 3
Explanation:
In the first operation, choose x = 1. Now, nums = [0,4,0,2,4].
In the second operation, choose x = 2. Now, nums = [0,2,0,0,2].
In the third operation, choose x = 2. Now, nums = [0,0,0,0,0].

Example 2:

Input: nums = [0]
Output: 0
Explanation: Each element in nums is already 0 so no operations are needed.
*/



class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        if(all_of(nums.begin(),nums.end(),[](int x) { return x == 0; })) { return 0;  }

        priority_queue<int,vector<int>,greater<int>> pri_que(nums.begin(),nums.end()),temp;

        while(!pri_que.empty()) {
            if(pri_que.top()!=0)  {
                temp.emplace(pri_que.top());
            }
            pri_que.pop();
        }

        int count = 0;
        for(size_t i = 0u;i<nums.size();i++) {
            int val = { 0 };
            while(!temp.empty()) {
                val = temp.top();
                temp.pop();
                if(val != 0) {
                    break;
                }
            }

            while(!temp.empty()) { temp.pop(); }

            std::for_each(nums.begin(), nums.end(), [val,&temp](int& x) {
                if(x>0) {
                    x -= val;
                    temp.emplace(x);
                }
            });

            if(all_of(nums.begin(),nums.end(),[](int x) { return x == 0; })) { return count;  }
        }

        return 0;
    }
};
