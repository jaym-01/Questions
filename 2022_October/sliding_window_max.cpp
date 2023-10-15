#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int bsPos(const vector<int>& nums, vector<int>& idx_qu, int i){
        int start = 0, end = idx_qu.size() - 1, mid;

        while(start < end){
            mid = (start + end) / 2;

            if(nums[i] >= nums[idx_qu[mid]]){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        return start;
    }

    void addQueue(const vector<int>& nums, vector<int>& idx_qu, int i){
        int j = bsPos(nums, idx_qu, i);

        idx_qu.erase(idx_qu.begin() + j, idx_qu.end());
        idx_qu.push_back(i);
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> idx_qu, out;

        // add elements to the queue
        for(int i = 0; i < k - 1; i++){
            addQueue(nums, idx_qu, i);
        }

        for(int i = 0; i + k - 1 < nums.size(); i++){
            if(!idx_qu.empty() && idx_qu[0] < i){
                // pop the queue
                idx_qu.erase(idx_qu.begin());
            }

            // add the new end
            addQueue(nums, idx_qu, i + k - 1);

            out.push_back(nums[idx_qu[0]]);
        }

        return out;
    }
};

int main(){
    Solution s;

    vector<int> t1 {9,10,9,-7,-4,-8,2,-6};

    vector<int> out = s.maxSlidingWindow(t1, 5);

    for(int val: out){
        cout << val << ", ";
    }

    cout << endl;
}