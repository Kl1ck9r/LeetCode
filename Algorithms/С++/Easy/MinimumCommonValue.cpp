
/*
Given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.
Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.
*/



// binarySearch O(LogN)
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int begin = 0, last = 0;
        while (begin < nums1.size() && last < nums2.size()) {
            if (nums1[begin] == nums2[last]) {
                return nums1[begin];
            }
            else if (nums1[begin] > nums2[last]) {
                last++;
            }
            else {
                begin++;
            }
        }
        return -1;
    }

};
