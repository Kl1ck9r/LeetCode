
/*

Given a string s, sort it in decreasing order based on the frequency of the characters. 
The frequency of a character is the number of times it appears in the string.
Return the sorted string. If there are multiple answers, return any of them.

*/


class Solution {
public:
	static bool cmp(pair<char, int>& a, pair<char, int>& b) {
		return a.second > b.second;
	}

	string frequencySort(string s) {
		unordered_map<char, int>mp;
		for (const auto it : s) {
			mp[it]++;
		}

		vector<pair<char, int>>res;
		for (const auto it : mp) {
			res.push_back(it);
		}
		sort(begin(res), end(res), cmp);

		string result = "";
		for (auto it : res) {
			int tmp = it.second;
			while (tmp--) {
				result += it.first;
			}
		}

		return result;
	}
};