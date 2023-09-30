/*
    Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
    You can use each character in text at most once. Return the maximum number of instances that can be formed.

    Example 1:

    Input: text = "nlaebolko"
    Output: 1

    Example 2:

    Input: text = "loonbalxballpoon"
    Output: 2

    Example 3:

    Input: text = "leetcode"
    Output: 0
*/


class Solution {
public:
    int maxNumberOfBalloons(string s) {
        const string ballon = "balloon";
        unordered_map<char,int> umap;

        for(const char ch:s) {
            if(ch =='b' || ch =='a' || ch=='l' || ch=='o'|| ch=='n')
                umap[ch]++;
        }

        for(const char ch:ballon) {
            if(umap.find(ch)==umap.end())
                return 0;
        }

        umap['o']=umap['o']/2;
        umap['l']=umap['l']/2;
        int result = INT_MAX;
        for(const auto it:umap)  {
            result = min(result,it.second);
        }
        return result == INT_MAX ? 0 : result;
    }
};
