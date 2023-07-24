
/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.


Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome

Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome

*/



// #1
class Solution {
public:
    bool isPalindrome(string s) {
        string newStr;
        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i]) || isalnum(s[i])) {
                newStr += tolower(s[i]);
            } else if (s[i] == ' ') {
                continue;
            }
        }

        string rendStr = newStr;
        reverse(newStr.begin(), newStr.end());

        if (rendStr == newStr) {
            return true;
        } else {
            return false;
        }
    }
};

// #2
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0,right = s.length() - 1;

        while(left<right) {
            while(left<right && !isalnum(s[left])) {
                left++;
            }

            while(left<right && !isalnum(s[right])) {
                right--;
            }

            if(tolower(s[right--])!=tolower(s[left++])) {
                return false;
            }
        }

        return true;
    }
};
