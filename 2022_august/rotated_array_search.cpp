#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, k = 0, out = -1;

        //find pivot
        for(int i = 0; i < (nums.size()/2) + 1; i++){
            if(nums[i + 1] < nums[i]){
                low = i + 1;
                high = i;
                k = nums.size() - low;
                break;
            }
            else if (nums[nums.size() - i - 1] < nums[nums.size() - i - 2]){
                low = nums.size() - i - 1;
                high = nums.size() - i - 2;
                k = i + 1;
                break;
            }
        }

        bool go = true;

        int sub_len = 0, mid;

        while(go){
            if(high == low){
                go = false;
            }

            if(high < low){
                sub_len = nums.size() - low + high + 1; // add 1 since high and low are indexes

                mid = (sub_len / 2) - k;
            }
            else if(high > low){
                mid = (high + low)/2;
            }
            else{
                mid = high;
            }

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
        }

        return out;
    }
};