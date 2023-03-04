

// o(n^2)
func BubbleSort() {
	nums := []int{10, 5, 3, 11, 9, 44}

	for i := len(nums) - 1; i > 0; i-- {
		for j := 0; j < i; j++ {
			if nums[j] > nums[j+1] {
				temp := nums[j]
				nums[j] = nums[j+1]
				nums[j+1] = temp

			}
		}
	}
}
