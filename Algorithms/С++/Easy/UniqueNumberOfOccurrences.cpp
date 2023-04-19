/*
		Given an array of integers arr, return true 
		if the number of occurrences of each value in the array is unique or false otherwise.
*/


class Solution {
public:
	bool uniqueOccurrences(vector<int>& arr) {
		unordered_map<int, int> mp;

		for (const auto it : arr) {
			mp[it]++;
		}

		vector<int> result;
		for (const auto it : mp) {
			result.push_back(it.second);
		}

		sort(result.begin(), result.end());
		auto it = std::unique(result.begin(), result.end());
		bool wasUnique = (it == result.end());
		return wasUnique;
	}
};