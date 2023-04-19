/*
 Given an array nums of n integers where nums[i] is in the range [1, n],
 return an array of all the integers in the range [1, n] that do not appear in nums.
*/

class Solution{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)  {
        vector<int> result{};
        unordered_map<int, bool> mp;

        for (size_t i = 0; i < nums.size(); i++){
            mp[nums[i]] = true;
        }

        for (size_t i = 1; i <= nums.size(); i++){
            if (mp.find(i) == mp.end()) {
                result.push_back(i);
            }
        }
        return result;
    }
};

