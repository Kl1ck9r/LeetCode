
/*
Given a non-empty array of integers nums,
 every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

func singleNumber(nums []int) int {
	mp := make(map[int]int)

	for _, i := range nums {
		mp[i]++
		if mp[i] > 1 {
			delete(mp, i)
		}
	}
	for j := range mp {
		return j
	}

	return 0
}