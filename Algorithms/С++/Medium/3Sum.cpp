/*
    Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
    Notice that the solution set must not contain duplicate triplets.

    Example 1:

    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
    Explanation:
    nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
    nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
    nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
    The distinct triplets are [-1,0,1] and [-1,-1,2].
    Notice that the order of the output and the order of the triplets does not matter.

    Example 2:

    Input: nums = [0,1,1]
    Output: []
    Explanation: The only possible triplet does not sum up to 0

    Example 3:

    Input: nums = [0,0,0]
    Output: [[0,0,0]]
    Explanation: The only possible triplet sums up to 0.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int>> result;
        if(nums.size() == 3) {
            if(accumulate(nums.begin(),nums.end(),0)!=0) {
                return result;
            } else {
                result.emplace_back(nums);
                return result;
            }
        } else if(nums.size() < 3) {
            return result;
        } else if(nums[0] > 0)  {
            return result;
        }


        constexpr int target = 0;
        set<vector<int>> vs;

        for(size_t i = 0;i<nums.size();i++) {
            int j = i + 1,k = nums.size() - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target) {
                    vs.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                } else if(sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        for(const auto elem : vs) {
            result.emplace_back(elem);
        }

        return result;
    }
};
