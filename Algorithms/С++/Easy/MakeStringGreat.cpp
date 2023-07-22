/*

    Given a string s of lower and upper case English letters.
    A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:
    0 <= i <= s.length - 2
    s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
    To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.
    Return the string after making it good. The answer is guaranteed to be unique under the given constraints.
    Notice that an empty string is also good.

*/


class Solution {
public:
    string makeGood(string s) {
        if(s == " ") {
            return s;
        }

        stack<char> m_stack;
        for(int i = 0;i<s.size();i++) {
            if(!m_stack.empty() && (m_stack.top() == tolower(s[i]) && isupper(s[i])
                                     || m_stack.top() == toupper(s[i]) && islower(s[i])))  {
                m_stack.pop();
            } else {
                m_stack.push(s[i]);
            }
        }

        string result = "";
        while(!m_stack.empty()) {
            result+=m_stack.top();
            m_stack.pop();
        }

        reverse(result.begin(),result.end());
        return result;
    }
};
