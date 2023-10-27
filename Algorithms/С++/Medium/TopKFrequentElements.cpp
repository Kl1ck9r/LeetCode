/*
Given an integer array nums and an integer k, return the k most frequent elements.
You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]
*/



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;

        for(const int num:nums) {
            umap[num]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> pri_que;

        for(const auto it:umap) {
            pri_que.emplace(make_pair(it.second,it.first));
        }

        vector<int> result;
        while(k!=0) {
            k--;
            result.emplace_back(pri_que.top().second); pri_que.pop();
        }

        return result;
    }
};
