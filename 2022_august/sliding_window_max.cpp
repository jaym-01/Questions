#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int end = k;
        vector<int> out;
        deque<int> q;

        for(int i = 0; i < k; i++){
            while(q.size() > 0 && nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }

        end++;
        out.push_back(nums[q.front()]);

        while(end <= nums.size()){
            if(end-k > q.front()){
                q.pop_front();
            }
            while(q.size() > 0 && nums[end - 1] >= nums[q.back()]){
                q.pop_back();
            }

            q.push_back(end - 1);
            out.push_back(nums[q.front()]);
            end++;
        }

        return out;
    }
};

int main(){
    Solution s;
    vector<int> t1 {7,2,4};

    vector<int> out1 = s.maxSlidingWindow(t1, 2);

    for(int i = 0; i < out1.size(); i++){
        cout << out1[i] << ", ";
    }

    cout << endl;
}