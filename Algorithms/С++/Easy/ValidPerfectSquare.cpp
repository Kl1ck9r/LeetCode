/*
    Учитывая положительное целое число, верните true if num — полный квадрат или false иначе .

    Идеальный квадрат — это целое число, которое является квадратом целого числа.
    Другими словами, это произведение некоторого целого числа само на себя.

    Вы не должны использовать какие-либо встроенные библиотечные функции, такие как sqrt.

    Example 1:

    Input: num = 16
    Output: true
    Explanation: We return true because 4 * 4 = 16 and 4 is an integer.

    Example 2:

    Input: num = 14
    Output: false
    Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.
*/


 class Solution {
 public:
     bool isPerfectSquare(int num) {
     int i = 1;
     while (num > 0) {
         num -= i;
         i += 2;
     }

       return num == 0;
     }
 };
