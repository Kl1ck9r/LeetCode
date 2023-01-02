
/*
You are given an array of strings words and a string pref.
Return the number of strings in words that contain pref as a prefix.
A prefix of a string s is any leading contiguous substring of s.
*/

func prefixCount(words []string, pref string) int {
	count := 0

	for _, word := range words {
		if strings.HasPrefix(word, pref) {
			count++
		}
	}

	return count
}