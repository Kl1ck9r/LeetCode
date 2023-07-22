    /*
    You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
    We repeatedly make duplicate removals on s until we no longer can.
    Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.
    */




class Solution{
public:
    string removeDuplicates(string s){
        stack<char> st;
        for(const auto c:s){
            if(!st.empty() && c==st.top()){
                st.pop();
            }else{
                st.push(c);
            }
        }

        string res="";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        reverse(res.begin(),res.end());
        return res;
    }
};
