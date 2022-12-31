
/*
Given two integer arrays nums1 and nums2, return an array of their
intersection. Each element in the result must be unique and you may return
the result in any order.
*/


class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

		set<int> s(nums1.begin(), nums1.end());

		vector<int>vec;

		for (int it : nums2) {
			if (s.erase(it))
				vec.push_back(it);
		}

		return vec;

	}
};