

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_map<int, int> map;

        for (const int i : nums) {
            if (++map[i] > 1) {
                return true;
            }
        }
        return false;
    }
};