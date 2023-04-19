
/*
You are given a string allowed consisting of distinct characters and an array of strings words.
A string is consistent if all characters in the string appear in the string allowed.
Return the number of consistent strings in the array words.
 */


class Solution {
public:
	int countConsistentStrings(string allowed, vector<string>& words) {
		bool answ[123] = {};
		int sz = words.size();

		for (const auto& it : allowed) {
			answ[it] = true;
		}

		for (const auto& it : words) {
			for (const auto ch : it) {
				if (!answ[ch]) {
					sz--;
					break;
				}
			}

		}
		return sz;
	}
};