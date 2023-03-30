/*

	Given a string s consisting of lowercase English letters, return the first letter to appear twice.
	Note: A letter a appears twice before another letter b if the second occurrence of a is before the second occurrence of b.
	s will contain at least one letter that appears twice.
*/


// #1 
class Solution {
public:
	char repeatedCharacter(std::string s) {
		auto it = std::adjacent_find(s.begin(), s.end());
		return *it;
	}

};

// #2 
class Solution {
public:
	char repeatedCharacter(string s) {
		char result;
		unordered_map<char, int> mp;

		for (const auto it : s) {
			if (mp.find(it) != mp.end()) {
				result = it;
				break;
			}
			mp[it]++;
		}
		return result;
	}
}

