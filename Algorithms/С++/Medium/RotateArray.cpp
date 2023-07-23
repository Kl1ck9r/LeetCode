/*
    Given an integer array nums, rotate the array to the right by k steps, where k is non-negative

    Example 1:

    Input: nums = [1,2,3,4,5,6,7], k = 3
    Output: [5,6,7,1,2,3,4]
    Explanation:
    rotate 1 steps to the right: [7,1,2,3,4,5,6]
    rotate 2 steps to the right: [6,7,1,2,3,4,5]
    rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/



// #1

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> _vec(n);
        k%=n;

        for(int i = 0;i<k;i++) {
            _vec[i] = nums[(n - k + i) % n];
        }

        for(int j = 0; j<n-k;j++) {
            _vec[k+j] = nums[j];
        }


        nums.assign(_vec.begin(),_vec.end());
    }
};


// #2

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        std::rotate(nums.rbegin(),nums.rbegin() + k % n,nums.rend());
    }
};


// #3

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = k%nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+n);
        reverse(nums.begin()+n,nums.end());
    }
};
