#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int end = k, max;
        vector<int> out;

        sort(nums.begin(), nums.begin() + k);

        max = nums[k - 1];
        out.push_back(max);

        while(end < nums.size()){
            if(nums[end] > max) max = nums[end];
            out.push_back(max);
            end++;
        }

        return out;
    }
};

int main(){
    Solution s;
    vector<int> t1 {1, -1};

    vector<int> out1 = s.maxSlidingWindow(t1, 3);

    for(int i = 0; i < out1.size(); i++){
        cout << out1[i] << ", ";
    }

    cout << endl;
}