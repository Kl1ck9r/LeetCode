
/*
Given a string s consisting of words and spaces, return the length
of the last word in the string.
A word is a maximal substring
consisting of non-space characters only.
*/

func lengthOfLastWord(s string) int {
	s = strings.TrimSpace(s) // removed space of the string in of the end and of the start
	result := strings.Split(s, " ")

	return len(result[len(result)-1])
}

// #2

func lengthOfLastWord(s string) int {
	result := strings.Fields(s)     // removed space of the string in of the end and of the start
	length := result[len(result)-1] // or just return len(result[len(result)-1])
	return len(length)
}
