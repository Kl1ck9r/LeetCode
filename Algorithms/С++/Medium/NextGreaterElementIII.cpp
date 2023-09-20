/*

    Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n.
    If no such positive integer exists, return -1.
    Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.


    Example 1:

    Input: n = 12
    Output: 21

    Example 2:

    Input: n = 21
    Output: -1
*/


class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> vec;
        int temp = n;

        while (n > 0) {
            vec.push_back(n % 10);
            n /= 10;
        }
        reverse(vec.begin(), vec.end());

        do {
            int num = 0;
            long j = 0;
            int s = vec.size() - 1;
            long i = pow(10,s);

            while(i>0)  {
                num+=i*vec[j++];
                i/=10;
            }

            if(num>temp) {
                return num;
            }

        }while(next_permutation(vec.begin(),vec.end()));

        return -1;
    }
};
