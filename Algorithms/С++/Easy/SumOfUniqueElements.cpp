
/*

You are given an integer array nums.
The unique elements of an array are the elements that appear exactly once in the array.
Return the sum of all the unique elements of nums.

*/


class Solution {
public:
	int sumOfUnique(vector<int>& nums) {
		map<int, int>mp;
		int sum = 0;
		for (const auto it : nums) {
			mp[it]++;
		}

		for (const auto it : mp) {
			if (it.second == 1) {
				sum += it.first;
			}
		}
		return sum;
	}
};