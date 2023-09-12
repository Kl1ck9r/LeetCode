/*
    You are given a 0-indexed integer array players, where players[i] represents the ability of the ith player.
    You are also given a 0-indexed integer array trainers, where trainers[j] represents the training capacity of the jth trainer.
    The ith player can match with the jth trainer if the player's ability is less than or equal to the trainer's training capacity.
    Additionally, the ith player can be matched with at most one trainer, and the jth trainer can be matched with at most one player.
    Return the maximum number of matchings between players and trainers that satisfy these conditions.

    Example 1:

    Input: players = [4,7,9], trainers = [8,2,5,8]
    Output: 2
    Explanation:
    One of the ways we can form two matchings is as follows:
    - players[0] can be matched with trainers[0] since 4 <= 8.
    - players[1] can be matched with trainers[3] since 7 <= 8.
    It can be proven that 2 is the maximum number of matchings that can be formed.

    Example 2:

    Input: players = [1,1,1], trainers = [10]
    Output: 1
    Explanation:
    The trainer can be matched with any of the 3 players.
    Each player can only be matched with one trainer, so the maximum answer is 1.
*/


class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end()); // 4 7 9 - способности игрока
        sort(trainers.begin(),trainers.end()); // 2 5 8 8 - способности тренеров
        // посчитать количество игроков у которых способности меньше способностей тренеров или равно
        // игроку можно сопоставить ему не больше одного тренера,также и к тренеру не больше одного игрока

        int count = 0;
        int left = 0,right = 0;
        int indexTrain = 1;
        int indexPlayers = 2;

        while(left<players.size() && right<trainers.size()) {
            if(players[left] <= trainers[right]) {
                if(indexTrain == right) {
                    right++;
                    continue;
                } else if(indexPlayers == left){
                    left++;
                    continue;
                }

                indexTrain = right;// 0
                indexPlayers = left; // 0
                count++;
                left++;
            }  else if(players[left]>trainers[right]) {
                right++;
            }
        }

        return count;
    }
};

