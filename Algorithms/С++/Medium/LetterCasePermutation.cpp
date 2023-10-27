/*
Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
Return a list of all possible strings we could create. Return the output in any order.

Example 1:

Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

Example 2:

Input: s = "3z4"
Output: ["3z4","3Z4"]
*/


class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string>result;
        result.emplace_back(s);

        for (size_t i = 0; i < s.length(); i++) {
            if (!isalpha(s[i])) {
                continue;
            }

            size_t size = result.size();
            for (size_t j = 0; j < size; j++) {
                string temp = result[j];
                if (islower(s[i])) {
                    temp[i] = toupper(s[i]);
                    result.emplace_back(temp);
                } else {
                    temp[i] = tolower(s[i]);
                    result.emplace_back(temp);
                }
            }
        }

        return result;
    }
};
