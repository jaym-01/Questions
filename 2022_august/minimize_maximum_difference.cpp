#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <map>
#include <algorithm>


using namespace std;

class Solution
{
public:
    int minimizeMax(vector<int> &nums, int p)
    {
        sort(nums.begin(), nums.end());

        int thresh = 0, pairs = 0, left = 0, right = nums[nums.size() - 1] - nums[0];

        while(left < right){
            pairs = 0;

            thresh = left + (right - left) / 2;

            for(int i = 0; i < nums.size() - 1; i++){
                if(abs(nums[i+1] - nums[i]) <= thresh){
                    pairs++;
                    i++;
                }
            }
            
            if(pairs >= p){
                right = thresh;
            }
            else{
                left = thresh + 1;
            }
        }

        return left;
    }

};

int main()
{
    Solution s;

    vector<int> t1{4,2,1,2};

    cout << s.minimizeMax(t1, 1) << endl;
}