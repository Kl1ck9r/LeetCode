/*

        Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k].
        If no such indices exists, return false

        Example 1:

        Input: nums = [1,2,3,4,5]
        Output: true
        Explanation: Any triplet where i < j < k is valid.

*/


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) {
            return false;
        }

        int min_val = std::numeric_limits<int>::max();
        int sec_min = std::numeric_limits<int>::max();

        for(const auto num:nums) {
            if(num<=min_val) {
                min_val = num;
            } else if(num<=sec_min) {
                sec_min = num;
            } else {
                return true;
            }
        }

        return false;
    }
};
