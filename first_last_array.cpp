#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int inx = binarySearch(nums, target, 0, nums.size() - 1);
        if(inx == -1){
            return {-1, -1};
        }

        int len2 = nums.size() - 1 - inx;

        int low = inx, high = inx;

        for(int i = 1; i <= max(inx, len2); i++){
            if(low > -1 && high < nums.size()){
                if (nums[high + 1] != target && nums[low - 1] != target)
                {
                    break;
                }
            }
            if(high < nums.size()){
                if(nums[high + 1] == target){
                    high++;
                }
                
            }
            if(low > -1){
                if(nums[low - 1] == target)
                {
                    --low;
                }
            }
        }

        return {low, high};
    }

    int binarySearch(const vector<int>& nums, int target, int low, int high){
        if(low <= high){
            int mid = (low + high) / 2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                return binarySearch(nums, target, low, mid - 1);
            }
            else{
                return binarySearch(nums, target, low + 1, high);
            }
        }
        else{
            return -1;
        }
    }
};

int main(){
    Solution s;
    vector<int> test = {2, 2};

    test = s.searchRange(test, 2);

    cout << test[0] << test[1] << endl;
}