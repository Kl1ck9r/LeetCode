

/*
Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.

*/

type RandomizedSet struct {
	mp   map[int]int
	nums []int
}

func Constructor() RandomizedSet {
	return RandomizedSet{
		mp:   make(map[int]int),
		nums: make([]int, 0),
	}
}

func (this *RandomizedSet) Insert(val int) bool {
	if _, ok := this.mp[val]; !ok {
		this.mp[val] = len(this.nums)
		this.nums = append(this.nums, val)
		return true
	}
	return false
}

func (this *RandomizedSet) Remove(val int) bool {
	if _, ok := this.mp[val]; ok {

		index := this.mp[val]
		this.mp[this.nums[len(this.nums)-1]] = index
		this.nums[index] = this.nums[len(this.nums)-1]
		this.nums = this.nums[0 : len(this.nums)-1]
		delete(this.mp, val)
		return true
	}
	return false
}

func (this *RandomizedSet) GetRandom() int {
	index := rand.Intn(len(this.nums))
	return this.nums[index]
}
