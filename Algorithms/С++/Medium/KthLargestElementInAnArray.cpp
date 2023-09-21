/*
    Given an integer array nums and an integer k, return the kth largest element in the array.
    Note that it is the kth largest element in the sorted order, not the kth distinct element.
    Can you solve it without sorting?

    Example 1:

    Input: nums = [3,2,1,5,6,4], k = 2
    Output: 5

    Example 2:

    Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
    Output: 4
*/



// firsy easy way
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),std::greater<int>());
        return nums[k-1];
    }
};

// second way

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,std::greater<int>> que;
        for(int num:nums) {
            que.push(num);
            if(que.size() > k) {
                que.pop();
            }
        }

        return que.top();
    }
};

// third way

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        partial_sort(nums.begin(),nums.begin()+k,nums.end(),std::greater<int>());
        return nums[k-1];
    }
};
