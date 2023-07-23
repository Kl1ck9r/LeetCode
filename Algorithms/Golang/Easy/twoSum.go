/*

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

*/

// #1 (o^2)
func twoSum(nums []int, target int) []int {
	n := len(nums)
	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			if nums[i]+nums[j] == target {
				return []int{i, j}
			}
		}
	}
	return []int{}
}

// #2 o(n)

func twoSum(nums []int, target int) []int {
	sort.Slice(nums,func(i,j int)bool{
		return nums[i]<nums[j]
	})
	
	begin, end := 0, len(nums)-1

	for begin < end {
		answ := (nums[end] + nums[begin])

		if answ == target {
			return []int{end, begin}
		} else if answ > target {
			end--
		} else {
			begin++
		}
	}

	return []int{}
}
