/*
    The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
    For example, the beauty of "abaacc" is 3 - 1 = 2.
    Given a string s, return the sum of beauty of all of its substrings.

    Example 1:

    Input: s = "aabcb"
    Output: 5
    Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.

    Example 2:

    Input: s = "aabcbaa"
    Output: 17
*/


class Solution {
public:
    int beautySum(string s) {
        int beautyCount = 0;
        unordered_map<char,int> ump;

        for(int i = 0;i<s.length();i++) {
            for(int j = i;j<s.length();j++) {
                ump[s[j]]++;

                int maxE = INT_MIN;
                int minE = INT_MAX;

                for(const auto it:ump) {
                    maxE = max(maxE,it.second);
                    minE = min(minE,it.second);
                }
                beautyCount+=(maxE - minE);
            }
            ump.clear();
        }
        return beautyCount;
    }
};

