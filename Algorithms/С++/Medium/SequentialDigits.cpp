/*
    An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
    Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

    Example 1:

    Input: low = 100, high = 300
    Output: [123,234]

    Example 2:

    Input: low = 1000, high = 13000
    Output: [1234,2345,3456,4567,5678,6789,12345]
*/


class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        string digits = "123456789";

        for(int len = 1; len <= 9; len++) { // перебираем количество цифр
            for(int i = 0; i <= 9 - len; i++) { // перебираем начальную цифру
                int num = stoi(digits.substr(i, len));
                if(num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }

        return result;
    }
};
