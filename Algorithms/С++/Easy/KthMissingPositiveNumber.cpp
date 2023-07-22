    /*
      Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
      Return the kth positive integer that is missing from this array.
    */

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> st(arr.begin(),arr.end());
        int missing_num = 0;
        for(int i  = 1;i<INT_MAX;++i){
          if(st.find(i)==st.end()){
             missing_num = i;
             --k;
             if(k==0){
                return missing_num;
             }
          }
        }
        return missing_num;
    }
};

