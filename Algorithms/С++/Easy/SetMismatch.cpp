
/*
    You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, 
    which results in repetition of one number and loss of another number.
    You are given an integer array nums representing the data status of this set after the error.
    Find the number that occurs twice and the number that is missing and return them in the form of an array.
*/


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> m1(nums.begin(), nums.end());
       
        vector<int> v(nums.size());
        iota(v.begin(), v.end(), 1);
  
        vector<int> m2(v.begin(), v.end());
        vector<int> ans(nums.size());
   
        auto it = set_difference(m1.begin(), m1.end(), m2.begin(), m2.end(), ans.begin());
        it = set_difference(m2.begin(), m2.end(), m1.begin(), m1.end(), ans.begin() + 1);

        ans.resize(2);
        return ans;
    }
};