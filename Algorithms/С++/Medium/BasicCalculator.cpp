/*
    Given a string s which represents an expression, evaluate this expression and return its value.
    The integer division should truncate toward zero.
    You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
    Note: You are not allowed to use any built-in func
*/


class Solution {
public:
    int calculate(string s) {
        stack<int> numStack;
        int num = 0;
        char op = '+';

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {
                if (op == '+') {
                    numStack.push(num);
                } else if (op == '-') {
                    numStack.push(-num);
                } else if (op == '*') {
                    int prevNum = numStack.top();
                    numStack.pop();
                    numStack.push(prevNum * num);
                } else if (op == '/') {
                    int prevNum = numStack.top();
                    numStack.pop();
                    numStack.push(prevNum / num);
                }

                op = s[i];
                num = 0;
            }
        }

        int result = 0;
        while (!numStack.empty()) {
            result += numStack.top();
            numStack.pop();
        }

        return result;
    }
};
