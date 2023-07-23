/*
    You are given an integer array nums. You are initially positioned at the array's first index,
    and each element in the array represents your maximum jump length at that position.
    Return true if you can reach the last index, or false otherwise.
*/



class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_index = 0;
        for(int i = 0; i < nums.size(); i++ ) {
            if(i > max_index) {
                return false;
            }

            max_index = max(max_index,i + nums[i]);
        }
        return true;
    }
};

