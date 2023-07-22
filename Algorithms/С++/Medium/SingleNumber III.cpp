
/*
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
Find the two elements that appear only once. You can return the answer in any order.
You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
*/


class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		unordered_set<int> st;
		vector<int> result;

		for (auto it : nums) {
			if (st.count(it)) {
				st.erase(it);
			}
			else {
				st.insert(it);
			}
		}
		return vector<int>(st.begin(), st.end());
	}
};
