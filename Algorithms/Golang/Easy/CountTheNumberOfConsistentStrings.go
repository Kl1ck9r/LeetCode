
/*
You are given a string allowed consisting of distinct characters and an array of strings words.
A string is consistent if all characters in the string appear in the string allowed.
Return the number of consistent strings in the array words.
*/

func countConsistentStrings(allowed string, words []string) int {

	count := 0

	for _, word := range words {
		for _, ch := range word {
			result := strings.ContainsRune(allowed, ch)

			if !result {
				count--
				break
			}
		}
		count++
	}

	return count
}