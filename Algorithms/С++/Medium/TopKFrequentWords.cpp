/*
Given an array of strings words and an integer k, return the k most frequent strings.
Return the answer sorted by the frequency from highest to lowest.
Sort the words with the same frequency by their lexicographical order.

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
*/



struct cmp {
public:
    bool operator()(pair<string, int>& a, pair<string, int>& b) {
        if(a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;

        for(const string word:words) {
            mp[word]++;
        }

        vector<string>result;
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pri_que;
        for(const auto it:mp) {
            pri_que.emplace(make_pair(it.first,it.second));
        }

        while(!pri_que.empty()) {
            k--;
            result.emplace_back(pri_que.top().first);
            pri_que.pop();

            if(k==0) {
                break;
            }
        }

        return result;
    }
};
