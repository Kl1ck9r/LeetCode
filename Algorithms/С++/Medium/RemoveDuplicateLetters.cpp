/*
    Given a string s, remove duplicate letters so that every letter appears once and only once.
    You must make sure your result is
    the smallest in lexicographical order among all possible results.


    Example 1:

    Input: s = "bcabc"
    Output: "abc"

    Example 2:

    Input: s = "cbacdcbc"
    Output: "acdb"
*/



class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool>used(26,false);
        vector<int>count(26,0);
        stack<char>st;

        for(char c:s){
            count[c-'a']++;
        }


        for(char c:s){
            count[c-'a']--;

            if(used[c-'a']) continue;

            while(!st.empty() && c<st.top() && count[st.top()-'a']>0) {
                used[st.top()-'a'] = false;
                st.pop();
            }

            st.push(c);
            used[c-'a'] = true;
        }


        string result = "";
        while(!st.empty()) {
            result = st.top() + result;
            st.pop();
        }


        return result;
    }
};
