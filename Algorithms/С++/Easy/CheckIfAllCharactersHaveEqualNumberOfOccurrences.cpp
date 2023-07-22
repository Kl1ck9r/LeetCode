
    /*
       Given a string s, return true if s is a good string, or false otherwise.
       A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).
    */


class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> mp;
        for (const auto &it : s) {
            mp[it]++;
        }

        int first_val = mp.begin()->second;
        bool isTrue = all_of(mp.begin(), mp.end(), [first_val](const auto &p)
                             { return p.second == first_val; });

        return isTrue;
    }
};
