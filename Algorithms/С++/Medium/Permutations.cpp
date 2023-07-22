	
/*
		Given an array nums of distinct integers, return all the possible permutations. 
		You can return the answer in any order.
*/

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		permute(nums, result, 0);
		return result;
	}

	void permute(vector<int> nums, vector<vector<int>>& result, int begin) {
		if (begin >= nums.size()) {
			result.push_back(nums);
			return;
		}
		else {
			for (int i = begin; i < nums.size(); ++i) {
				swap(nums[begin], nums[i]);			// 1 2 3 
				permute(nums, result, begin + 1);	// 2 3 1  
			}
		}
	}
};