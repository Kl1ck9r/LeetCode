


// O(n)
func ShakeSort(nums []int) {
	right, left := 0, len(nums)-1

	for left <= right {
		for i := right; i > left; i-- {
			if nums[i] < nums[i-1] {
				temp := nums[i-1]
				nums[i-1] = nums[i]
				nums[i] = temp
			}
		}
		left++

		for j := left; j < right; j++ {
			if nums[j] > nums[j+1] {
				temp := nums[j]
				nums[j] = nums[j+1]
				nums[j+1] = temp
			}
		}
		right--
	}
}
