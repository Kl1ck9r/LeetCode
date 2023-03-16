
/*
	Given two strings ransomNoteand magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
	Each letter in magazine can only be used once in ransomNote.
*/


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;

        for (const auto it : magazine) {
            mp[it]++;
        }

        for (const auto it : ransomNote) {
            mp[it]--;
        }

        for (const auto it : mp) {
            if (it.second < 0) {
                return false;
            }
        }

        return true;
    }
};