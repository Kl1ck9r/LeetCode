    /*
        Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.
        The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.
    */


class Solution {
public:
    int remainderOfDivision(int num1, int num2) {
        while(num2!=0) {
            num1%=num2;
            swap(num1,num2);
        }
        return num1;
    }

    int findGCD(vector<int> &nums) {
        int mn = 0, mx = 0;
        mx = *max_element(nums.begin(), nums.end());
        mn = *min_element(nums.begin(), nums.end());
        auto remainder = remainderOfDivision(mx, mn);
        return remainder;
    }
};
