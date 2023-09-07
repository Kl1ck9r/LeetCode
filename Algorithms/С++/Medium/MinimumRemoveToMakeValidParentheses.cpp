/*
    Given a string s of '(' , ')' and lowercase English characters.
    Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
    Formally, a parentheses string is valid if and only if:

    It is the empty string, contains only lowercase characters, or
    It can be written as AB (A concatenated with B), where A and B are valid strings, or
    It can be written as (A), where A is a valid string.

    Example 1:

    Input: s = "lee(t(c)o)de)"
    Output: "lee(t(c)o)de"
    Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
    Example 2:

    Input: s = "a)b(c)d"
    Output: "ab(c)d"
*/


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        vector<int> indexesToRemove;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }  else if(s[i]==')'){
                if(st.empty()){
                    indexesToRemove.push_back(i);
                }
                else{
                    st.pop();
                }
            }
        }

        while(!st.empty()){
            indexesToRemove.push_back(st.top());
            st.pop();
        }

        sort(indexesToRemove.begin(),indexesToRemove.end());

        for(int i=indexesToRemove.size()-1;i>=0;i--){
            int index = indexesToRemove[i];
            s.erase(index,1);
            for(int j=i;j<indexesToRemove.size();j++){
                if(indexesToRemove[j]>index){
                    indexesToRemove[j]--;
                }
            }
        }

        string res = s;
        return res;
    }
};
