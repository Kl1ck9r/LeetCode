/*
    Given an array of strings words, return the first palindromic string in the array.
    If there is no such string, return an empty string "".
    A string is palindromic if it reads the same forward and backward.

    Example 1:

    Input: words = ["abc","car","ada","racecar","cool"]
    Output: "ada"
    Explanation: The first string that is palindromic is "ada".
    Note that "racecar" is also palindromic, but it is not the first.

    Example 2:

    Input: words = ["notapalindrome","racecar"]
    Output: "racecar"
    Explanation: The first and only string that is palindromic is "racecar".
*/




// first way
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i = 0;i<words.size();i++) {
            string temp = words[i];
            reverse(temp.begin(),temp.end());
            if(words[i] == temp) {
                return words[i];
            }
        }

        return "";
    }
};


// second way
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i = 0;i<words.size();i++) {
            int left = 0,right = words[i].size() - 1;

            while(left<right) {
                if(words[i][left]!=words[i][right]) {
                    break;
                }
                left++;
                right--;
            }

            if(left>=right) {
                return words[i];
            }
        }

        return "";
    }
};
