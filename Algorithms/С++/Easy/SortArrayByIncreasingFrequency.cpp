
/*

Given an array of integers nums, sort the array in increasing order based on the frequency of the values.
If multiple values have the same frequency, sort them in decreasing order.
Return the sorted array.

*/


class Solution {
public:
	vector<int> frequencySort(vector<int>& nums) {
		map<int, int> mp;

		for (const auto it : nums) {
			mp[it]++;
		}

		auto t_sort = [&mp](const int& i, const int& j) {
			if (mp[i] == mp[j]) {
				return i > j;
			}
			else {
				return mp[i] < mp[j];
			}
		};

		sort(nums.begin(), nums.end(), t_sort);

		return nums;
	}
};