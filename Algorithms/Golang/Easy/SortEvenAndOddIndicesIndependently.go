
/*

You are given a 0-indexed integer array nums. Rearrange the values of nums according to the following rules:
Sort the values at odd indices of nums in non-increasing order.
For example, if nums = [4,1,2,3] before this step, it becomes [4,3,2,1] after. The values at odd indices 1 and 3 are sorted in non-increasing order.
Sort the values at even indices of nums in non-decreasing order.
For example, if nums = [4,1,2,3] before this step, it becomes [2,1,4,3] after. The values at even indices 0 and 2 are sorted in non-decreasing order.
Return the array formed after rearranging the values of nums.

*/

func sortEvenOdd(nums []int) []int {
	st1, st2 := []int{}, []int{}
	for i := 0; i < len(nums); i++ {
		if i%2 == 0 {
			st1 = append(st1, nums[i])
			sort.Slice(st1, func(i, j int) bool {
				return st1[i] < st1[j]
			})
		} else {
			st2 = append(st2, nums[i])
			sort.Slice(st2, func(i, j int) bool {
				return st2[i] > st2[j]
			})
		}
	}

	answ := []int{}
	i, j := 0, 0

	for k := 0; k < len(nums); k++ {
		if k%2 == 0 {
			answ = append(answ, st1[i])
			i++
		} else {
			answ = append(answ, st2[j])
			j++
		}
	}

	return answ
}
