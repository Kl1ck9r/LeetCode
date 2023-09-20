 
/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]
*/



class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;

        result.emplace_back(nums);

        while(next_permutation(nums.begin(),nums.end())) {
            result.emplace_back(nums);
        }

        return result;
    }
};

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        nextPermutation(nums,result,0);
        return result;
    }

private:
    void nextPermutation(vector<int> nums, vector<vector<int>>& output, int idx) {
        if(idx == nums.size()) {
            output.emplace_back(nums);
        }

        for(int i = idx;i<nums.size();i++) {
            if(idx!=i && nums[i] == nums[idx]) continue;
            swap(nums[i],nums[idx]);
            nextPermutation(nums,output,idx+1);
        }
    }
};

