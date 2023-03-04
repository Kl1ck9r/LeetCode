
/*

Given an array of integers nums which is sorted in ascending order, and an integer target,
 write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity.

*/

// O(LogN)
func search(nums []int, target int) int {
    right:=len(nums)-1
    left:=0

    for left <=right{
        middle:=(right+left)/2
        if nums[middle]==target{
            return middle
        }else if nums[middle]<target{
                 left = middle +1
        }else{
             right = middle -1
        }
    }   
    return -1
}