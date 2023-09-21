/*
    Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

    Example 1:

    Input: nums = [3,2,3]
    Output: [3]

    Example 2:

    Input: nums = [1]
    Output: [1]

    Example 3:

    Input: nums = [1,2]
    Output: [1,2]

*/


// first way
 class Solution {
 public:
     vector<int> majorityElement(vector<int>& nums) {
         vector<int> result;
         unordered_map<int,int> mp;

         for(const int num:nums) {
           mp[num]++;
         }

         for(const auto it:mp) {
           if(it.second>nums.size()/3) {
             result.push_back(it.first);
           }
         }
         return result;
     }
 };


 // second way
 class Solution {
 public:
     vector<int> majorityElement(vector<int>& nums) {
         vector<int> result;
         map<int,int> mp;

       for(const int num: nums) {
         if(mp.find(num) == mp.end()) {
           mp[num] = 1;
         } else {
           mp[num]++;
         }
       }

       for(const auto it:mp) {
         if(it.second>nums.size()/3) {
           result.push_back(it.first);
         }
       }

       return result;
     }
 };
