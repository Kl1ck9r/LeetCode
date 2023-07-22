/*
    You are given a string s, which contains stars *.
    In one operation, you can:
    Choose a star in s.

    Remove the closest non-star character to its left, as well as remove the star itself.
    Return the string after all stars have been removed.

    Note:

    The input will be generated such that the operation is always possible.
    It can be shown that the resulting string will always be unique.
*/


// #1 string method

class Solution {
public:
    string removeStars(string s) {
        string result = "";
        for(char c : s) {
            if(c == '*') {
                result.pop_back();
            } else {
                result+=c;
            }
        }
        return result;
    }
};


// #2 stack method

class Solution {
public:
    string removeStars(string s) {
        stack<char> m_stack;

        for(char c : s) {
            if(c == '*') {
                m_stack.pop();
            } else {
                m_stack.push(c);
            }
        }

        string result = "";
        for(;;) {
            if(m_stack.empty()) {
                break;
            }

            result += m_stack.top();
            m_stack.pop();
        }

        reverse(result.begin(),result.end());
        return result;
    }
};

