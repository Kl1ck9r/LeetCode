
/*

You are given an integer array nums. A number x is lonely when it appears only once, 
and no adjacent numbers (i.e. x + 1 and x - 1) appear in the array.
Return all lonely numbers in nums. You may return the answer in any order.

*/


class Solution {
public:
	vector<int> findLonely(vector<int>& nums) {
		vector<int> answ;
		map<int, int>mp;
		for (const auto it : nums) {
			mp[it]++;
		}

		for (const auto it : mp) {
			if (mp.count(it.first + 1) == 0 && mp.count(it.first - 1) == 0 && it.second == 1) {
				answ.push_back(it.first);
			}
		}


		return answ;
	}
};