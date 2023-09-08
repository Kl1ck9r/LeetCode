/*
    Given a string s, reverse only all the vowels in the string and return it.
    The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

    Example 1:

    Input: s = "hello"
    Output: "holle"

    Example 2:

    Input: s = "leetcode"
    Output: "leotcede"
*/


class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;

        while(left<right) {
            if(isVowel(s[left]) && isVowel(s[right])) {
                swap(s[left],s[right]);
                left++;
                right--;
            } else if(isVowel(s[left])) {
                right--;
            } else {
                left++;
            }
        }

        return s;
    }

    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
