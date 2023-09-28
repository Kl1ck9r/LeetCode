/*
    Given a string of English letters s, return the greatest English letter which occurs as both a lowercase and uppercase letter in s.
    The returned letter should be in uppercase. If no such letter exists, return an empty string.
    An English letter b is greater than another letter a if b appears after a in the English alphabet.

    Example 1:

    Input: s = "lEeTcOdE"
    Output: "E"
    Explanation:
    The letter 'E' is the only letter to appear in both lower and upper case.

    Example 2:

    Input: s = "arRAzFif"
    Output: "R"
    Explanation:
    The letter 'R' is the greatest letter to appear in both lower and upper case.
    Note that 'A' and 'F' also appear in both lower and upper case, but 'R' is greater than 'F' or 'A'.

    Example 3:

    Input: s = "AbCdEfGhIjK"
    Output: ""
    Explanation:
    There is no letter that appears in both lower and upper case.
*/



// hash table use
class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char>ump;

        for(const char ch:s){
            if(ch>='a' && ch<='z') {
                ump.insert(ch);
            }
        }

        string result="";
        char temp = 'A';

        for(char c:s){
            if ((c >= 'A' && c <= 'Z') && ump.find(tolower(c)) != ump.end()) {
                if(temp<=c) {
                    result.clear();
                    result.push_back(c);
                    temp = c;
                }
            }
        }

        return result;
    }
};


// vector use
class Solution {
public:
    string greatestLetter(string s) {
        vector<int> low(26),upp(26);

        for(char ch:s) {
            if(ch>='a' && ch<='z')
                low[ch-'a']++;
            else
                upp[ch-'A']++;
        }

        string result;
        for(int i = 25;i>=0;i--){
            if(low[i] && upp[i]) {
                result+='A'+i;
                break;
            }
        }

        return result;
    }
};
