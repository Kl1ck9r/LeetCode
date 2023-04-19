
/*
You are given an array of strings words and a string pref.
Return the number of strings in words that contain pref as a prefix.
A prefix of a string s is any leading contiguous substring of s.
*/

class Solution {
public:
	int prefixCount(vector<string>& words, string pref) {

		int count = 0;

		for (const auto& it : words) {
			if (it.substr(0, pref.length()) == pref) {
				count++;
			}
		}

		return count;
	}
};