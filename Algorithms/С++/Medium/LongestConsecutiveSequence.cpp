/*
    Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
    You must write an algorithm that runs in O(n) time.

    Example 1:

    Input: nums = [100,4,200,1,3,2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

    Example 2:

    Input: nums = [0,3,7,2,5,8,4,6,0,1]
    Output: 9
*/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return {};

        set<int> s(nums.begin(), nums.end());

        int count = 1;
        int maxCount = 1;

        auto it = s.begin();
        int prev = *it;
        it++;

        for(; it != s.end(); it++) {
            if(*it - prev == 1) {
                count++;
                if(count > maxCount) {
                    maxCount = count;
                }
            } else {
                count = 1;
            }
            prev = *it;
        }
        return maxCount;
    }
};
