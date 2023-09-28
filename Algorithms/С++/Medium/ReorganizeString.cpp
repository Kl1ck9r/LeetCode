 /*
    Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
    Return any possible rearrangement of s or return "" if not possible.

    Example 1:

    Input: s = "aab"
    Output: "aba"

    Example 2:

    Input: s = "aaab"
    Output: ""
*/



class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>ump;

        for(const char c:s)
            ump[c]++;

        priority_queue<pair<int,char>> maxHeap;
        string result;

        for(const auto it:ump)
            maxHeap.push(make_pair(it.second,it.first));

        while(maxHeap.size() > 1) {
            auto pair1 = maxHeap.top(); maxHeap.pop();
            auto pair2 = maxHeap.top(); maxHeap.pop();

            result+=pair1.second; result+=pair2.second;
            pair1.first--; pair2.first--;

            if(pair1.first>0) {
                maxHeap.push(pair1);
            }

            if(pair2.first>0){
                maxHeap.push(pair2);
            }
        }

        if(!maxHeap.empty()) {
            if(maxHeap.top().first>1)
                return "";
            else
                result+=maxHeap.top().second;
        }
        return result;
    }
};
