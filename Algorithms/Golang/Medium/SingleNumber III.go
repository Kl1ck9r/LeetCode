
/*
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
Find the two elements that appear only once. You can return the answer in any order.
You must write an algorithm that runs in linear runtime complexity and uses only constant extra space
*/


func singleNumber(nums []int) []int {
    mp:=make(map[int]int)
    var ans []int


    for _,i:=range nums{
        mp[i]++
    }

    for i,j:=range mp{
        if j==1{
            ans = append(ans,i)
        }
    }
    return ans
}