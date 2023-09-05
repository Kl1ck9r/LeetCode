/*
    Given an array of positive integers nums and a positive integer target, return the minimal length of a
    subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

    Example 1:

    Input: target = 7, nums = [2,3,1,2,4,3]
    Output: 2
    Explanation: The subarray [4,3] has the minimal length under the problem constraint.

    Example 2:

    Input: target = 4, nums = [1,4,4]
    Output: 1

*/


// first way

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int left = 0;
        int result = INT_MAX;

        for(int i = 0;i<n;i++) {
            sum+=nums[i];
            while(sum>=target) {
                result = min(result,i - left +1);
                sum-=nums[left];
                left++;
            }
        }

        return (result==INT_MAX) ? 0 : result;
    }
};

// second way


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int sum = nums[left];
        int result = INT_MAX;

        while(right < nums.size()) {
            if(sum >=target) {
                result = min(result,right - left + 1);
                sum-=nums[left];
                left++;
            } else {
                right++;
                if(right < nums.size()) {
                    sum+=nums[right];
                }
            }
        }

        return (result!=INT_MAX) ? result : 0;
    }
};
