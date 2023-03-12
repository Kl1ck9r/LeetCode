/*
	Given a binary array nums, return the maximum number of consecutive 1's in the array.

	* Input: nums = [1,1,0,1,1,1]
	* Output: 3 
*/

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int result = 0;
		int count = 0;
		for (size_t i = 0u; i < nums.size(); i++) {
			if (nums[i] == 0) {
				count = 0;
			}
			else {
				count++;
				result = max(result, count);
			}
		}
		return result;
	}
};