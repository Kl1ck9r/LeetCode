    /*
       Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.
       Return the largest lucky integer in the array. If there is no lucky integer return -1.
    */


class Solution {
public:
    int findLucky(vector<int> &arr) {
        int result = 0;
        unordered_map<int, int> mp;

        for (auto it : arr) {
            mp[it]++;
        }

        vector<int> count;
        for (const auto it : mp) {
            if (it.second == it.first) {
                count.push_back(it.first);
            }
        }

        if (count.size() > 0){
            return *max_element(count.begin(), count.end());
        }

        return -1;
    }
};
