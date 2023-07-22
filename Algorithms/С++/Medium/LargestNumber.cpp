/*

Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
Since the result may be very large, so you need to return a string instead of an integer.

*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (all_of(nums.begin(), nums.end(), [](int num) {return num == 0; }))
            return "0"; // if string equal just "0" then return 
        vector<string> strs;
        transform(nums.begin(), nums.end(), back_inserter(strs), [](int num) {return to_string(num); });
        // sort and turn into string 

        sort(strs.begin(), strs.end(), [](string& l, string& r) {return l + r > r + l; });

        return accumulate(strs.begin(), strs.end(), string(""));
    }
}