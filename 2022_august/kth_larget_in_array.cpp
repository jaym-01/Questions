#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // sort(nums.begin(), nums.end());
        // return nums[nums.size() - k];

        int tmp = 0, tmp_idx = -1, out;
        bool max = false;

        if (k < (nums.size() / 2))
        {
            // start by finding the largest
            max = true;
            tmp = numeric_limits<int>::min();
        }
        else
        {
            k = nums.size() - k + 1;
            tmp = numeric_limits<int>::max();
        }

        while (k != 0)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (max && nums[i] > tmp)
                {
                    tmp = nums[i];
                    tmp_idx = i;
                }
                else if (!max && nums[i] < tmp)
                {
                    tmp = nums[i];
                    tmp_idx = i;
                }
            }

            nums.erase(nums.begin() + tmp_idx);
            if(k == 1){
                break;
            }
            else if(max){
                tmp = numeric_limits<int>::min();
            }
            else{
                tmp = numeric_limits<int>::max();
            }
            --k;
        }

        return tmp;
    }
};

int main()
{
    Solution s;
    vector<int> t1{1, 2, 3, 4, 5};

    cout << s.findKthLargest(t1, 6) << endl;
}