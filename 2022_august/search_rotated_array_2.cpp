#include <iostream>
#include <vector>

using namespace std;

#define n nums.size()

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // find pivot
        int lowest = find_pivot(nums);

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
    int find_pivot(vector<int>& nums){
        int ref = nums[n - 1], low = 0, high = n - 1, mid;

        while(low < high){
            mid = (low + high) / 2;

            if(nums[mid] == ref){

                int j = mid - 1;

                while(j != mid){
                    if(nums[j] == ref){
                        if(j == low){
                            j = high - 1;
                        }
                        else{
                            --j;
                        }
                    }
                    else{
                        break;
                    }
                }

                low = j + 1;
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
    vector<int> t1 {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};

    // cout << s.search(t1, 10) << endl;

    cout << s.find_pivot(t1) << endl;
    // cout << s.binary_search(t1, 0, t1.size() - 1, 1) << endl;
}