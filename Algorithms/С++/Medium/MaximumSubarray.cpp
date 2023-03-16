	
/*
	Given an integer array nums, find the subarray with the largest sum, and return its sum.
*/


class Solution1 {
public:
	int maxSubArray(vector<int>& nums) {
		// Kadane's algorithm 
		int sum = 0, maxN = INT_MIN;

		for (const auto it : nums) {
			sum += it;

			maxN = max(maxN, sum);

			if (sum < 0) {
				sum = 0;
			}
		}
		return maxN;
	}
};