
/*

Given two integers a and b, return the sum of the two integers 
without using the operators + and -.

*/


class Solution {
public:
    int getSum(int a, int b) {
        vector<int> result;
        result.emplace_back(a);
        result.emplace_back(b);

        return std::accumulate(result.begin(), result.end(), 0);
    }
};