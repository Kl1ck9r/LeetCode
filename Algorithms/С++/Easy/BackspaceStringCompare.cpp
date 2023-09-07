/*
    Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
    Note that after backspacing an empty text, the text will continue empty.

    Example 1:

    Input: s = "ab#c", t = "ad#c"
    Output: true
    Explanation: Both s and t become "ac".
    Example 2:

    Input: s = "ab##", t = "c#d#"
    Output: true
    Explanation: Both s and t become "".
*/




class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;
        int i = 0;

        for (char c : s) {
            if (c == '#') {
                if (!st1.empty()) st1.pop();
            } else {
                st1.push(c);
            }
        }

        for (char c : t) {
            if (c == '#') {
                if (!st2.empty()) st2.pop();
            } else {
                st2.push(c);
            }
        }

        while (!st1.empty() && !st2.empty()) {
            if (st1.top() != st2.top()) return false;
            st1.pop();
            st2.pop();
        }

        return st1.empty() && st2.empty();
    }
};
