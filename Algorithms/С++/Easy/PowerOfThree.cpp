 /*
    Given an integer n, return true if it is a power of three. Otherwise, return false.
    An integer n is a power of three, if there exists an integer x such that n == 3x.

    Example 1:

    Input: n = 27
    Output: true
    Explanation: 27 = 33

    Example 2:

    Input: n = 0
    Output: false
    Explanation: There is no x where 3x = 0.

    Example 3:

    Input: n = -1
    Output: false
    Explanation: There is no x where 3x = (-1).

*/

 // loop way
 class Solution {
 public:
     bool isPowerOfThree(int n) {
         if(n<=0) {
             return false;
         }

         if(n==1) {
             return true;
         }

         int x = 1;
         int max_int_div_3 = INT_MAX / 3;

         while(x<n) {
             if(x>max_int_div_3) {
                 break;
             }

             x= x * 3;
             if(x== n) {
                 return true;
             }
         }

         return false;
     }
 };


 // recursive way


 class Solution {
 public:
     bool isPowerOfThree(int n) {
         return isPowerOfThreeHelper(n,1);
     }

     bool isPowerOfThreeHelper(int n,int x) {
         if(n<=0) {
             return false;
         }

         if (n == x) {
             return true;
         }

         if (x > INT_MAX / 3) {
             return false;
         }

         return isPowerOfThreeHelper(n,x*3);
     }
 };
