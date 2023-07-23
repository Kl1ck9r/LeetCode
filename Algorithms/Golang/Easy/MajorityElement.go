
/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.
*/

func majorityElement(nums []int) int {
	mp := make(map[int]int)

	for _, i := range nums {
		mp[i]++
	}

	var result int
	for index, j := range mp {
		if j > len(nums)/2 {
			result = index
			break
		}
	}
	return result

}