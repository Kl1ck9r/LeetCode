/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.


Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/


// very slow
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;

        for(size_t i = 0;i<nums.size();i++) {
            int idx = i;
            int idx_t = 0;
            int num = 1;

            while(idx_t<nums.size()) {
                if(idx_t==idx) {
                    idx_t++;
                    continue;
                }

                num = nums[idx_t] * num;
                idx_t++;
            }
            result.emplace_back(num);
        }

        return result;
    }
};



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        int left = 1;
        for (int i = 0; i < n; i++) {
            result[i] *= left;
            left *= nums[i];
        }

        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= right;
            right *= nums[i];
        }

        return result;
    }
};
