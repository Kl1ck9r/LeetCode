
/*

You are given a 0-indexed integer array nums. Rearrange the values of nums according to the following rules:
Sort the values at odd indices of nums in non-increasing order.
For example, if nums = [4,1,2,3] before this step, it becomes [4,3,2,1] after. The values at odd indices 1 and 3 are sorted in non-increasing order.
Sort the values at even indices of nums in non-decreasing order.
For example, if nums = [4,1,2,3] before this step, it becomes [2,1,4,3] after. The values at even indices 0 and 2 are sorted in non-decreasing order.
Return the array formed after rearranging the values of nums.

*/



class Solution {
public:
	vector<int> sortEvenOdd(vector<int>& nums) {
		vector<int> vec, vec2;
		for (int i = 0; i < nums.size(); i++) {
			if (i % 2 == 0) {
				vec.emplace_back(nums[i]);
				sort(vec.begin(), vec.end());
			}
			else  if (i % 2 != 0) {
				vec2.emplace_back(nums[i]);
				sort(vec2.begin(), vec2.end(), greater<int>());
			}
		}

		vector<int> answ(nums.size());
		int vecI = 0, vecJ = 0;

		for (int i = 0; i < answ.size(); i++) {
			if (i % 2 == 0) {
				answ[i] = vec[vecI];
				vecI++;
			}
			else {
				answ[i] = vec2[vecJ];
				vecJ++;
			}
		}

		return answ;
	}
};