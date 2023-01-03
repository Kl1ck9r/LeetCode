
/*
Given an integer array nums, move all the even integers
 at the beginning of the array followed by all the odd integers.
Return any array that satisfies this condition.
*/

func sortArrayByParity(nums []int) []int {
	index := 0

	for i := 0; i < len(nums); i++ {
		if nums[i]%2 == 0 {
			nums[index], nums[i] = nums[i], nums[index]
			index++
		}
	}
	return nums
}