/*
    You are given an m x n integer matrix matrix with the following two properties:

    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.
    Given an integer target, return true if target is in matrix or false otherwise.

    You must write a solution in O(log(m * n)) time complexity.

    Example 1:

    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    Output: true

    Example 2:

    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
    Output: false
*/


// first way

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int columns = matrix[0].size();

        bool found = false;
        for(int i = 0;i<rows;i++) {
            for(int j = 0;j<columns;j++) {
                if(matrix[i][j] == target) {
                    found = true;
                    break;
                }
            }
        }
        return found;
    }
};

// second way

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<int> curr(rows * columns);
        int k = 0;
        bool found = false;

        for(int i = 0;i< rows;i++)  {
            for(int j = 0;j<columns;j++) {
                curr[k++] = matrix[i][j];
            }
        }

        int left = 0,right = curr.size() - 1;
        int middle = 0;

        while(left<=right) {
            middle = left + (right - left) / 2;
            if(curr[middle] == target) {
                found = true;
                break;
            } else if(curr[middle] < target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        return found;
    }
};
