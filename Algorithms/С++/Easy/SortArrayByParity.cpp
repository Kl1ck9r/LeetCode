
/*
Given an integer array nums, move all the even integers at the beginning 
of the array followed by all the odd integers.
Return any array that satisfies this condition.
*/


class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& nums) {
		for (int i = 0, j = 0; j < nums.size(); j++) {
			if (nums[j] % 2 == 0) {
				swap(nums[i++], nums[j]);
			}
		}
		return nums;
	}
};


// #2

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& nums) {
		std::partition(nums.begin(), nums.end(), [](int i) {
			return i % 2 == 0;
			});
		return nums;
	}
};