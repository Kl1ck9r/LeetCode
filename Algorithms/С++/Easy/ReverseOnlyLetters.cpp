/*

    Given a string s, reverse the string according to the following rules:
    All the characters that are not English letters remain in the same position.
    All the English letters (lowercase or uppercase) should be reversed.
    Return s after reversing it.

    Example 1:

    Input: s = "ab-cd"
    Output: "dc-ba"

    Example 2:

    Input: s = "a-bC-dEf-ghIj"
    Output: "j-Ih-gfE-dCba"
*/



class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0, right = s.length() - 1;

        while(left<right) {
            if(isLetter(s[left]) && isLetter(s[right])) {
                swap(s[left],s[right]);
                right--;
                left++;
            } else if(isLetter(s[left])) {
                right--;
            } else {
                left++;
            }
        }
        return s;
    }

    bool isLetter(char c) {
        return c>='a' && c<='z' || c>='A' && c<='Z';
    }
};
