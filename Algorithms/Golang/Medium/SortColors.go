
/*
Given an array nums with n objects colored red, white, or blue,
sort them in-place so that objects of the same color are adjacent, with the colors
in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.
*/

func sortColors(nums []int) {

	var zero, one, two int = 0, 0, 0

	for _, count := range nums {
		if count == 0 {
			zero++
		} else if count == 1 {
			one++
		} else {
			two++
		}

		for i := 0; i < zero; i++ {
			nums[i] = 0
		}
		for j := zero; j < one+zero; j++ {
			nums[j] = 1
		}

		for k := zero + one; k < two+one+zero; k++ {
			nums[k] = 2
		}
	}
}
