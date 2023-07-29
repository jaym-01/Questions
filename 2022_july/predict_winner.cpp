#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return all_combos(nums, 0, nums.size() - 1, new int[2]{0, 0}, true);        
    }

private:
    bool all_combos(vector<int>& nums, int low, int high, int* players, bool p1_turn){
        int p2 = players[1];
        if(high < low){

            if(players[0] >= players[1]){
                return true;
            }
            return false;
        }
        else{

            players[(int)!p1_turn] += nums[low];
            bool diff1 = all_combos(nums, low + 1, high, players, !p1_turn);

            players[(int)!p1_turn] -= nums[low];
            players[(int)!p1_turn] += nums[high];
            bool diff2 = all_combos(nums, low, high - 1, players, !p1_turn);

            players[(int)!p1_turn] -= nums[high];

            if(p1_turn){
                //if player 1 turn - it will alaways try to take the route it will win with
                return diff1 || diff2;
            }
            else{
                //if p2 turn
                //it will always try to take the route where p1 loses
                return diff1 && diff2;
            }

        }

    }
};

int main(){
    Solution s1;

    vector<int> in1 {1,5,2};
    cout << s1.PredictTheWinner(in1) << endl;
}