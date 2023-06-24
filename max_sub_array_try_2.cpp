#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        vector<int> mem;
        mem.push_back(nums[0]);

        for(int i = 0; i < nums.size(); i++){

            if(nums[i] > max){
                max = nums[i];
            }

            for(int j = i + 1; j < nums.size(); j++){
                if(i == 0){
                    mem.push_back(mem[j - 1] + nums[j]);
                }
                else{
                    mem[j] -= nums[i - 1];
                }

                if(mem[j] > max){
                    max = mem[j];
                }
            }

        }

        return max;
    }
};