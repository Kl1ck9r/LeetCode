/*
    Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned.
    It is guaranteed there is at least one word that is not banned, and that the answer is unique.
    The words in paragraph are case-insensitive and the answer should be returned in lowercase.

    Example 1:

    Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
    Output: "ball"

    Explanation:
    "hit" occurs 3 times, but it is a banned word.
    "ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph.
    Note that words in the paragraph are not case sensitive,
    that punctuation is ignored (even if adjacent to words, such as "ball,"),
    and that "hit" isn't the answer even though it occurs more because it is banned.

    Example 2:

    Input: paragraph = "a.", banned = []
    Output: "a"
*/


class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> umap;

        vector<string> vec;
        string temp;


        for(int i = 0;i<paragraph.length();i++) {
            if(isalpha(paragraph[i])) {
                temp += tolower(paragraph[i]);
            } else {
                if(!temp.empty()) {
                    vec.push_back(temp);
                    temp.clear();
                }
            }
        }

        if(!temp.empty()) {
            vec.push_back(temp);
        }

        for(int i = 0;i<vec.size();i++) {
            bool isBanned = false;
            for(int j = 0;j<banned.size();j++) {
                if(vec[i] == banned[j]) {
                    isBanned = true;
                    break;
                }
            }

            if(!isBanned) {
                umap[vec[i]]++;
            }
        }

        string result;
        int mostCommon = INT_MIN;
        for(const auto it:umap) {
            if(mostCommon<it.second) {
                mostCommon = it.second;
                result = it.first;
            }
        }
        return result;
    }
};


