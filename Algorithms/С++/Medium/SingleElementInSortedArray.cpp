
   /*
    You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
    Return the single element that appears only once.
    Your solution must run in O(log n) time and O(1) space
   */


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int result = 0;
        unordered_multiset<int> st(nums.begin(),nums.end());

        for(const auto& it:st) {
            if(st.count(it)==1) {
                result = it;
            }
        }
        return  result;
    }
};
