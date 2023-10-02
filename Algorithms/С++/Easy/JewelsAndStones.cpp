/*
    You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have.
    Each character in stones is a type of stone you have.
    You want to know how many of the stones you have are also jewels.
    Letters are case sensitive, so "a" is considered a different type of stone from "A".

    Example 1:

    Input: jewels = "aA", stones = "aAAbbbb"
    Output: 3

    Example 2:

    Input: jewels = "z", stones = "ZZ"
    Output: 0
*/



// more preferred and more productive
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int>count; // red-black tree

        for(int i=0;i<stones.size();i++)
            count[stones[i]]++;

        int num=0;
        for(int i=0;i<jewels.size();i++)
            num+=count[jewels[i]];

        return num;
    }
};

// second way
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> umap; // hash-table

        for(const char ch:stones) {
            umap[ch]++;
        }

        int num = 0;
        for(const char ch:jewels) {
            for(auto it = umap.begin();it!=umap.end();++it) {
                if(it->first == ch) {
                    num+=it->second--;
                }
            }
        }
        return num;
    }
};

