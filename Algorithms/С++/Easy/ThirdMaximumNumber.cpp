 /*
    Given an integer array nums, return the third distinct maximum number in this array.
    If the third maximum does not exist, return the maximum number.

    Example 1:

    Input: nums = [3,2,1]
    Output: 1
    Explanation:
    The first distinct maximum is 3.
    The second distinct maximum is 2.
    The third distinct maximum is 1.

    Example 2:

    Input: nums = [1,2]
    Output: 2
    Explanation:
    The first distinct maximum is 2.
    The second distinct maximum is 1.
    The third distinct maximum does not exist, so the maximum (2) is returned instead
*/



 // way with use array,but bad and not effective
 class Solution {
 public:
     int thirdMax(vector<int>& nums) {
         sort(nums.begin(),nums.end(),greater<int>());

         auto end = nums.end();
         for (auto it = nums.begin(); it != end; ++it) {
             end = std::remove(it + 1, end, *it);
         }

         nums.erase(end, nums.end());

         if(nums.size()<3) {
             return nums[0];
         }

         int maxE = INT_MIN;
         int maxThird = 0;
         int k = 2;

         for(int i = 0;i<nums.size();i++) {
             if(nums[i]>maxE) {
                 maxE = nums[i];
             }  else if(maxThird>nums[i]) {
                 maxThird = nums[i];
                 k--;
                 if(k==0) {
                     break;
                 }

             }
         }

         return maxThird;
     }
 };

 // way with use set
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int,greater<int>>s(nums.begin(),nums.end());

        if(s.size() < 3) {
            return *s.begin();
        } else {
            auto it = s.begin();
            advance(it,2);
            return *it;
        }
    }
};



// way with use priority_queue
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int,vector<int>,less<int>> pque;
        set<int> st;


        for(const int num:nums) {
            st.insert(num);
        }

        for(const int num:st) {
            pque.push(num);
        }


        if(pque.size()<3) {
            return pque.top();
        } else {
            pque.pop();
            pque.pop();
            return pque.top();
        }
    }
};
