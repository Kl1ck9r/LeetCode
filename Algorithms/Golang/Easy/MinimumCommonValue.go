/*

Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. 
If there is no common integer amongst nums1 and nums2, return -1.
Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

*/

// binarySearch (LogN)
func getCommon(nums1 []int, nums2 []int) int {
    last,begin:=0,0

    for begin<len(nums1) && last<len(nums2){
        if nums1[begin]==nums2[last]{
            return nums1[begin]
        }else if nums1[begin]<nums2[last] {
           begin++
        }else{
            last++
        }
    }
    return -1
}