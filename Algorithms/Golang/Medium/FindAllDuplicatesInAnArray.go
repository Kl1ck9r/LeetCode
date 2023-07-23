
/*
Given an integer array nums of length n where all the integers
of nums are in the range [1, n] and each integer appears once or twice,
return an array of all the integers that appears twice.
You must write an algorithm that runs in O(n) time and uses only constant extra space.
*/

func findDuplicates(nums []int) []int {

	var result []int
	mp := make(map[int]bool, 0)

	for i := 0; i < len(nums); i++ {
		if mp[nums[i]] == true {
			result = append(result, nums[i])
		} else {
			mp[nums[i]] = true
		}
	}
	return result
}