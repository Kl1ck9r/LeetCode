/*
A sentence is a string of single-space separated words where each word consists only of lowercase letters.
A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
Given two sentences s1 and s2, return a list of all the uncommon words.
You may return the answer in any order.

Example 1:

Input: s1 = "this apple is sweet", s2 = "this apple is sour"
Output: ["sweet","sour"]

Example 2:

Input: s1 = "apple apple", s2 = "banana"
Output: ["banana"]
*/

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> result;
        unordered_map<string,int> umap;

        s1+=" ";
        s1+=s2;

        string temp;
        for(char c:s1) {
            if(c == ' ') {
                umap[temp]++;
                temp.clear();
            } else {
                temp+=c;
            }
        }

        if(!temp.empty()) {
            umap[temp]++;
        }

        for(const auto it:umap) {
            if(it.second == 1) {
                result.push_back(it.first);
            }
        }

        return result;
    }
};
