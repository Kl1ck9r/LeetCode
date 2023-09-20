
/*
    Given two integer arrays arr1 and arr2, and the integer d, return the distance value between the two arrays.
    The distance value is defined as the number of elements arr1[i] such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.

    Example 2:

    Input: arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
    Output: 2

    Example 3:

    Input: arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
    Output: 1
*/



// first way
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;

        for(int i=0; i<arr1.size(); i++) {
            bool flag = true;
            for(int j=0; j<arr2.size(); j++) {
                if(abs(arr1[i]-arr2[j]) <= d) {
                    flag = false;
                    break;
                }
            }
            if(flag) count++;
        }
        return count;
    }
};
