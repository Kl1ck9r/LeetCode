/*
    You are given a string s consisting only of uppercase English letters.
    You can apply some operations to this string where,
    in one operation, you can remove any occurrence of one of the substrings "AB" or "CD" from s.
    Return the minimum possible length of the resulting string that you can obtain.
    Note that the string concatenates after removing the substring and could produce new "AB" or "CD" substrings.
*/


class Solution {
public:
    int minLength(string s) {
        stack<char> m_stack;

        for(char c : s) {
            if(m_stack.empty()) {
                m_stack.push(c);
            } else {
                if(c == 'B' && m_stack.size() && m_stack.top() == 'A') {
                    m_stack.pop();
                } else if(c == 'D' && m_stack.size() && m_stack.top() == 'C') {
                    m_stack.pop();
                } else {
                    m_stack.push(c);
                }
            }
        }
        return m_stack.size();
    }
};
