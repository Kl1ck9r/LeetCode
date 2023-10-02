/*
    You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.
    Permute the characters of s so that they match the order that order was sorted.
    More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.
    Return any permutation of s that satisfies this property.


    Example 1:

    Input: order = "cba", s = "abcd"
    Output: "cbad"
    Explanation:
    "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".
    Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.

    Example 2:

    Input: order = "cbafg", s = "abcd"
    Output: "cbad"
*/


class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> umap;

        for(const char ch:s) {
            umap[ch]++;
        }

        string result;
        for(int i = 0;i<order.size();i++) {
            if(umap.find(order[i])!=umap.end()) {
                while(umap[order[i]]) {
                    result+=order[i];
                    umap[order[i]]--;
                }
                umap.erase(order[i]);
            }

        }

        for(auto it=umap.begin();it!=umap.end();++it){
            while(it->second!=0) {
                result+=it->first;
                it->second--;
            }
        }
        return result;
    }
};
