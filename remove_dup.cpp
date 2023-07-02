#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr_ix = 0, tmp = -101;

        for(int i = 0; i < nums.size(); i++){
            if(tmp == -101 || nums[i] != tmp){
                tmp = nums[i];
                nums[curr_ix] = tmp;
                curr_ix++;
            }
        }

        return curr_ix;
    }
};

int main(){
    Solution s1;

    vector<int> test1 {0,0,1,1,1,2,2,3,3,4};

    cout << s1.removeDuplicates(test1) << endl;

    return 0;
}