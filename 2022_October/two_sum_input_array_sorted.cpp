#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int tmp;

        for(int i = 0; i < numbers.size() - 1; i++){
            tmp = bs(numbers, i + 1, numbers.size() - 1, target - numbers[i]);
            if(tmp != -1) return vector<int>({i + 1, tmp + 1});
        }

        return vector<int>();
    }

    int bs(const vector<int>& nums, int start, int end, int target){
        int mid;
        
        while(start <= end){
            mid = (start + end + 1) / 2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target) end = mid - 1;
            else start = mid + 1;
        }

        return -1;
    }
};

int main(){
    Solution s;

    vector<int> test {2, 3, 4};

    test = s.twoSum(test, 6);

    for(auto val: test){
        cout << val << endl;
    }
}