#include <iostream>
#include <vector>

using namespace std;

#define n nums.size()

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // find pivot
        int lowest = find_pivot(nums, 0, n - 1, true);

        if(target >= nums[lowest] && target <= nums[n - 1]){
            return binary_search(nums, lowest, n - 1, target);
        }
        else if(lowest > 0 && target <= nums[lowest - 1] && target >= nums[0]){
            return binary_search(nums, 0, lowest - 1, target);
        }
        else{
            return false;
        }
    }

// private:
    int find_pivot(vector<int>& nums, int low, int high, bool first){
        int ref = nums[n - 1], mid;

        while(low < high){
            mid = (low + high) / 2;

            if(nums[mid] == ref){
                int p_l = find_pivot(nums, low, mid, false);
                int p_r = find_pivot(nums, mid + 1, high, false);

                if(p_l > low && nums[p_l - 1] > nums[p_l]){
                    return p_l;
                }
                else if(p_r > low && nums[p_r - 1] > nums[p_r]){
                    return p_r;
                }
                else if(p_l <= low && nums[high] >= nums[p_l]){
                    return p_l;
                }
                else{
                    return p_r;
                }
            }
            else if(nums[mid] > ref){
                low = mid + 1;
            }
            else{
                high = mid;
                ref = nums[mid];
            }
        }

        return low;
    }

    bool binary_search(vector<int>& nums, int low, int high, int target){
        if(low > high){
            return false;
        }
        else{
            int mid = (low + high) / 2;

            if(nums[mid] == target){
                return true;
            }
            else if(nums[mid] > target){
                return binary_search(nums, low, mid - 1, target);
            }
            else{
                return binary_search(nums, mid + 1, high, target);
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> t1 {2,5,6,0,0,1,2};

    // cout << s.search(t1, 10) << endl;

    cout << s.find_pivot(t1, 0, t1.size() - 1, true) << endl;
    // cout << s.binary_search(t1, 0, t1.size() - 1, 1) << endl;
}