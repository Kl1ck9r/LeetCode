
    /*
        Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
        A string is represented by an array if the array elements concatenated in order forms the string.
    */

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
       auto it1 = accumulate(word1.begin(),word1.end(),string{});
       auto it2 = accumulate(word2.begin(),word2.end(),string{});

       if(it1==it2) {
        return true;
       }

      return false;
    }
};
