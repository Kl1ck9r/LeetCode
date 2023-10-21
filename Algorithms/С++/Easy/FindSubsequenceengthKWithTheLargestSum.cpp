/*
You are given an integer array nums and an integer k.
You want to find a subsequence of nums of length k that has the largest sum.
Return any such subsequence as an integer array of length k.
A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

Example 1:

Input: nums = [2,1,3,3], k = 2
Output: [3,3]
Explanation:
The subsequence has the largest sum of 3 + 3 = 6.

Example 2:

Input: nums = [-1,-2,3,4], k = 3
Output: [-1,3,4]
Explanation:
The subsequence has the largest sum of -1 + 3 + 4 = 6.

Example 3:

Input: nums = [3,4,3,3], k = 2
Output: [3,4]
Explanation:
The subsequence has the largest sum of 3 + 4 = 7.
Another possible subsequence is [4, 3].
*/


class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        if(nums.size() == k) return nums;

        priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> pri_que;

        for(size_t i = 0u;i<nums.size();i++) {
            pri_que.emplace(make_pair(nums[i],i));
        }

        vector<int>indexes;
        while(k!=0) {
            indexes.emplace_back(pri_que.top().second); pri_que.pop();
            k--;
        }

        sort(indexes.begin(),indexes.end());
        vector<int> result;
        for(const int num:indexes) {
            result.emplace_back(nums[num]);
        }

        return result;
    }
};
