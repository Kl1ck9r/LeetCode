/*
	Given an array nums of integers, return how many of them contain an even number of digits.
*/


class Solution {
public:

	int divider(int n) {
		return n ? 1 + divider(n / 10) : 0;
	}

	int findNumbers(vector<int>& nums) {
		int n_index = 0;

		for (const auto it : nums) {
			if (divider(it) % 2 == 0)
				n_index++;
		}

		return n_index;
	}
};