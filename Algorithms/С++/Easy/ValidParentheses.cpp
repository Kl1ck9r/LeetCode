/*
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
    An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.
*/



class Solution {
public:
    bool isValid(string s) {
        stack<char> m_stack;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                m_stack.push(s[i]);
            } else if (s[i] == ')' || s[i] == '}' || s[i] == ']')  {
                if (m_stack.empty() || (s[i] == ')' && m_stack.top() != '(') || (s[i] == '}'
                                                                                 && m_stack.top() != '{') || (s[i] == ']' && m_stack.top() != '[')) {
                    return false;
                } else {
                    m_stack.pop();
                }
            } else {
                continue;
            }
        }
        return m_stack.empty();
    }
};
