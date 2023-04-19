/*
		Given three integer arrays nums1, nums2, and nums3,
		return a distinct array containing all the values that are present in at least two out of the three arrays. 
		You may return the values in any order.	
*/


class Solution {
public:
	vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
		vector<int> answ;
		set<int> st1, st2, st3;

		for (const auto it1 : nums1) {
			st1.insert(it1);
		}

		for (const auto it2 : nums2) {
			st2.insert(it2);
		}

		for (const auto it3 : nums3) {
			st3.insert(it3);
		}

		map<int, int> mp;
		for (const auto it1 : st1) {
			mp[it1]++;
		}

		for (const auto it2 : st2) {
			mp[it2]++;
		}

		for (const auto it3 : st3) {
			mp[it3]++;
		}

		vector<int> result;
		for (const auto it : mp) {
			if (it.second >= 1) {
				result.emplace_back(it.first);
			}
		}
		return result;
	}
};