
/*

Given an array of integers nums, sort the array in increasing order based on the frequency of the values.
 If multiple values have the same frequency, sort them in decreasing order.
Return the sorted array.

*/

func frequencySort(nums []int) []int {
	seen := map[int]int{}

	for _, v := range nums {
		seen[v]++
	}

	sort.Slice(nums, func(i, j int) bool {
		if seen[nums[i]] == seen[nums[j]] {
			return nums[j] < nums[i]
		}
		return seen[nums[i]] < seen[nums[j]]
	})

	return nums
}
