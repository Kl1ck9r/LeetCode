/*
        Two strings are considered close if you can attain one from the other using the following operations:

        Operation 1: Swap any two existing characters.
        For example, abcde -> aecdb
        Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
        For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
        You can use the operations on either string as many times as necessary.

        Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.


        Example 1:

        Input: word1 = "abc", word2 = "bca"
        Output: true
        Explanation: You can attain word2 from word1 in 2 operations.
        Apply Operation 1: "abc" -> "acb"
        Apply Operation 1: "acb" -> "bca"
*/




class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }

        vector<int> count1(26),count2(26);
        unordered_set<char> st1,st2;

        for(const auto ch:word1) {
            count1[ch-'a']++;
            st1.insert(ch);
        }

        for(const auto ch:word2) {
            count2[ch-'a']++;
            st2.insert(ch);
        }

        sort(count1.begin(),count1.end());
        sort(count2.begin(),count2.end());

        return st1 == st2 && count1 == count2;

    }
};
