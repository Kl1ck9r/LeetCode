/*
    Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates).
    You may return the answer in any order.

    Example 1:

    Input: words = ["bella","label","roller"]
    Output: ["e","l","l"]

    Example 2:

    Input: words = ["cool","lock","cook"]
    Output: ["c","o"]
*/


class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        unordered_map<char, int> umap;

        for (const auto& ch : words[0]) {
            umap[ch]++;
        }

        for (int i = 1; i < words.size(); i++) {
            unordered_map<char, int> umapc;

            for (const auto& ch : words[i]) {
                umapc[ch]++;
            }

            for (auto it = umap.begin(); it != umap.end();) {
                if (umapc.find(it->first) == umapc.end()) {
                    it = umap.erase(it);
                } else {
                    it->second = min(it->second, umapc[it->first]);
                    ++it;
                }
            }
        }

        for (const auto& p : umap) {
            for (int i = 0; i < p.second; i++) {
                result.push_back(string(1, p.first));
            }
        }

        return result;
    }
};

