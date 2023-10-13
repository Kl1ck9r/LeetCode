/*
You are given a positive integer num. You may swap any two digits of num that have the same parity (i.e. both odd digits or both even digits).
Return the largest possible value of num after any number of swaps.

Example 1:

Input: num = 1234
Output: 3412
Explanation: Swap the digit 3 with the digit 1, this results in the number 3214.
Swap the digit 2 with the digit 4, this results in the number 3412.
Note that there may be other sequences of swaps but it can be shown that 3412 is the largest possible number.
Also note that we may not swap the digit 4 with the digit 1 since they are of different parities.

Example 2:

Input: num = 65875
Output: 87655
Explanation: Swap the digit 8 with the digit 6, this results in the number 85675.
Swap the first digit 5 with the digit 7, this results in the number 87655.
Note that there may be other sequences of swaps but it can be shown that 87655 is the largest possible number.
*/



class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> odd,even;
        vector<int>nums1,nums2;

        do {
            int digit = num % 10;
            if(digit % 2 == 0) {
                even.emplace(digit);
            } else {
                odd.emplace(digit);
            }
            num/=10;
            nums1.emplace_back(digit);
        } while(num!=0);

        reverse(nums1.begin(),nums1.end());

        for(const int num:nums1) {
            if(num % 2 == 0) {
                nums2.emplace_back(even.top());
                even.pop();
            } else {
                nums2.emplace_back(odd.top());
                odd.pop();
            }
        }

        int result = 0;
        for(const int num:nums2) {
            result = result * 10 + num;
        }

        return result;
    }
};
