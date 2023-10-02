/*
    Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
    In other words, return true if one of s1's permutations is the substring of s2.

    Example 1:

    Input: s1 = "ab", s2 = "eidbaooo"
    Output: true
    Explanation: s2 contains one permutation of s1 ("ba").

    Example 2:

    Input: s1 = "ab", s2 = "eidboaoo"
    Output: false
*/



class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;

        vector<int>count(256,0);
        for (int i = 0; i < s1.length(); i++) {
            count[s1[i]]++;
            count[s2[i]]--;
        }

        if(all_of(count.begin(),count.end(),[](int x) { return x == 0; }))  return true;

        for(int i = s1.length();i<s2.length();i++) {
            count[s2[i]]--;
            count[s2[i-s1.length()]]++;
            if(all_of(count.begin(),count.end(),[](int x) { return x == 0; }))  return true;
        }

        return false;
    }
};
