#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, k = 0;

        if(nums.size() < 3){
            if(nums[0] == target){
                return 0;
            }
            else if(nums.size() == 2 && nums[1] == target){
                return 1;
            }
            else{
                return -1;
            }
        }

        //find pivot
        for(int i = 0; i < (nums.size()/2) + 1; i++){

            if(i + 1 < nums.size() && nums[i + 1] < nums[i]){
                low = i + 1;
                high = i;
                k = nums.size() - low;
                break;
            }
            
            else if (nums.size() - i - 2 > 0 && nums[nums.size() - i - 1] < nums[nums.size() - i - 2]){
                low = nums.size() - i - 1;
                high = nums.size() - i - 2;
                k = i + 1;
                break;
            }
        }

        int out;

        out = bs(nums, target, low, nums.size() - 1);

        if(out == -1){
            return bs(nums, target, 0, high);
        }
        else{
            return out;
        }

        // bool iterate = true;

        // int sub_len = 0, mid;

        // while(iterate){
        //     if(high == low){
        //         iterate = false;
        //     }

        //     if(high < low){
        //         sub_len = nums.size() - low + high + 1; // add 1 since high and low are indexes

        //         mid = (sub_len / 2 + low) % nums.size();
        //     }
        //     else if(high > low){
        //         // sub_len = high - low;
        //         mid = (high + low)/2;
        //     }
        //     else{
        //         mid = high;
        //     }

        //     if(nums[mid] == target){
        //         return mid;
        //     }
        //     else if(nums[mid] > target){
        //         high = mid - 1;
        //         if(high < 0){
        //             high = nums.size() + high; 
        //         }

        //     }
        //     else{
        //         low = (mid + 1) % nums.size();

        //     }
        // }

        // return -1;
    }

private:

    int bs(vector<int>& nums, int target, int low, int high){
        if(high < low){
            return -1;
        }
        else{
            int mid = (high + low) / 2;

            if(nums[mid] == target) return mid;
            else if(nums[mid] > target){
                return bs(nums, target, low, mid - 1);
            }
            else{
                return bs(nums, target, mid + 1, high);
            }
        }
    }
};

int main(){
    Solution s1;
    vector<int> t1 {4,5,6,7,8,1,2,3};

    cout << s1.search(t1, 8) << endl; 
}