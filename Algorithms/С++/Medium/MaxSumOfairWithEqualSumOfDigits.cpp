/*
You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].
Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.

Example 1:

Input: nums = [18,43,36,13,7]
Output: 54
Explanation: The pairs (i, j) that satisfy the conditions are:
- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
So the maximum sum that we can obtain is 54.

Example 2:

Input: nums = [10,12,19,14]
Output: -1
Explanation: There are no two numbers that satisfy the conditions, so we return -1.
*/


class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,priority_queue<int>> umap;

        for(int i = 0;i<nums.size();i++) {
            umap[getSum(nums[i])].emplace(nums[i]);

        }

        int result = INT_MIN;
        for(auto &it:umap) {
            if(it.second.size()>1)  {
                int t1 = it.second.top(); it.second.pop();
                int t2 = it.second.top(); it.second.pop();
                result = max(result,t1+t2);
            }
        }

        return result == INT_MIN ? -1 : result;
    }

private:
    int getSum(int val) {
        int sum = 0;

        while(val>0) {
            sum+=val % 10;
            val/=10;
        }

        return sum;
    }
};
