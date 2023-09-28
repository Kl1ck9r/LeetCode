 /*
    Given two arrays of strings list1 and list2, find the common strings with the least index sum.
    A common string is a string that appeared in both list1 and list2.
    A common string with the least index sum is a common string such that if it appeared at list1[i] and list2[j] then i + j should be the minimum value among all the other common strings.
    Return all the common strings with the least index sum. Return the answer in any order.


    Example 1:

    Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]
    Output: ["Shogun"]
    Explanation: The only common string is "Shogun".

    Example 2:

    Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KFC","Shogun","Burger King"]
    Output: ["Shogun"]
    Explanation: The common string with the least index sum is "Shogun" with index sum = (0 + 1) = 1.
*/


class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> ump;

        for(int i = 0;i<list1.size();i++) {
            ump[list1[i]] = i;
        }

        vector<string>result;
        int minIndex = INT_MAX;

        for(int j = 0;j<list2.size();j++){
            if(ump.count(list2[j])) {
                int indexSum = j + ump[list2[j]];
                if(indexSum<minIndex) {
                    result.clear();
                    result.push_back(list2[j]);
                    minIndex = indexSum;
                } else if(indexSum == minIndex) {
                    result.push_back(list2[j]);
                }
            }
        }

        return result;
    }
};
