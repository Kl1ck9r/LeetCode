
/*
	Given an integer array nums, return the most frequent even element.
	If there is a tie, return the smallest one. If there is no such element, return -1.
*/

class Solution {
public:
	int  mostFrequentEven(vector<int>& nums) {
		map<int, int> mp;

		for (const auto it : nums) {
			mp[it]++;
		}
		int ans = -1, max = -1;

		for (const auto m : mp) {
			if (m.first % 2 == 0 && m.second > max) {
				ans = m.first;
				max = m.second;
			}
		}

		return ans;
	}
};