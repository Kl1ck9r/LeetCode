
/*
You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.
For each index i, names[i] and heights[i] denote the name and height of the ith person.
Return names sorted in descending order by the people's heights.
*/

func sortPeople(names []string, heights []int) []string {
	mp := make(map[int]string)

	for i, _ := range names {
		mp[heights[i]] = names[i]
	}

	sort.Ints(heights)
	var result []string

	for i := len(heights) - 1; i >= 0; i-- {
		result = append(result, mp[heights[i]])
	}

	return result
}