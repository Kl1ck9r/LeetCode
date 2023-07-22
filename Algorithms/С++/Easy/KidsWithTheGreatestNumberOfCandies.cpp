/*
    There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.
    Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.
    Note that multiple kids can have the greatest number of candies.
*/



class Solution {
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        std::transform(candies.begin(), candies.end(), candies.begin(), [extraCandies](int i)
                       { return i + extraCandies; });

        auto max_candies = *std::max_element(candies.begin(), candies.end());

        vector<bool> vec;
        vec.reserve(candies.size());
        std::transform(candies.begin(), candies.end(), std::back_inserter(vec), [max_candies, extraCandies](int i)
                       { return (i + extraCandies) >= max_candies; });

        return vec;
    }
};
