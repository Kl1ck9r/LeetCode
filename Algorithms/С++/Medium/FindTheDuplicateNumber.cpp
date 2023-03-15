/*
     Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
    There is only one repeated number in nums, return this repeated number.
    You must solve the problem without modifying the array nums and uses only constant extra spac

*/


// #1 

class Solution {
public:
    int findDuplicate(vector<int>& vec) {
        sort(vec.begin(), vec.end());
        int n = 0;
        for (size_t i = 0u; i < vec.size() - 1; i++) {
            if (vec[i] == vec[i + 1]) {
                n = vec[i];
            }
        }
        return n;
    }
};


// #2 
class Solution {
public:
	int findDuplicate(vector<int>& vec) {
		int number = 0;
		unordered_map<int, int> mp;
		for (const auto it : vec) {
			mp[it]++;
		}

		for (const auto it : mp) {
			if (it.second > 1) {
				number = it.first;
			}
		}
		return number;
	}
};

// #3
class Solution {
public:
	int findDuplicate(vector<int>& vec) {
		int number = 0;
		unordered_set<int> st;

		for (size_t i = 0; i < vec.size(); i++) {
			if (st.find(vec[i]) != st.end())
				number = vec[i];
			else
				st.insert(vec[i]);
		}
		return number;
	}
};