/*
Given an integer array nums containing distinct positive integers, find and return any number from the array that is neither the minimum nor the maximum value in the array, or -1 if there is no such number.
Return the selected integer.

Example 1:

Input: nums = [3,2,1,4]
Output: 2
Explanation: In this example, the minimum value is 1 and the maximum value is 4. Therefore, either 2 or 3 can be valid answers.

Example 2:

Input: nums = [1,2]
Output: -1
Explanation: Since there is no number in nums that is neither the maximum nor the minimum, we cannot select a number that satisfies the given condition. Therefore, there is no answer.

Example 3:

Input: nums = [2,1,3]
Output: 2
Explanation: Since 2 is neither the maximum nor the minimum value in nums, it is the only valid answer.
*/


// #1
class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        auto it_max = max_element(begin(nums),end(nums));
        int idx_max = *it_max;

        auto it_min = min_element(begin(nums),end(nums));
        int idx_min = *it_min;

        if(nums.size() == 0)
            return -1;

        int val = INT_MIN;

        for(size_t i = 0;i<nums.size();i++) {
            if(nums[i] == idx_min || nums[i] == idx_max)  continue;
            else val = nums[i]; break;
        }

        return val == INT_MIN ? -1 : val;
    }
};

// #2
class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int val = { 0 };

        for_each(nums.begin(),nums.end(),[&val,&nums](int x) {
            int min_v = *min_element(begin(nums),end(nums));
            int max_v = *max_element(begin(nums),end(nums));

            if(x!=min_v && x!=max_v) {
                val = x;
            }
        });

        return val == 0 ? -1 : val;
    }
};


// #3

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(const auto &i: nums){
            if((i != nums[0]) && (i != nums[nums.size()-1])) return i;
        }

        return -1;
    }
};
