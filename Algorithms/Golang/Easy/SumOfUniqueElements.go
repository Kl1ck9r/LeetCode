
/*

You are given an integer array nums.
The unique elements of an array are the elements that appear exactly once in the array.
Return the sum of all the unique elements of nums.

*/

func sumOfUnique(nums []int) int {
	mp := make(map[int]int)
	sum := 0

	for _, v := range nums {
		mp[v]++
	}

	for i := range mp {
		if mp[i] == 1 {
			sum += i
		}
	}

	return sum
}
