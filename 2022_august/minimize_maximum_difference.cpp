#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <map>

using namespace std;

// class Solution
// {
// public:
//     int minimizeMax(vector<int> &nums, int p)
//     {
//         if (p == 0)
//         {
//             return 0;
//         }

//         vector<int> diffs;
//         int crnt_min, crnt_val, tmp, j;
//         map<int, int> used; // other index used, minimum value

//         for (int i = 0; i < nums.size() - 1; i++)
//         {
//             crnt_val = nums[i];
//             crnt_min = numeric_limits<int>::max();

//             for (j = i + 1; j < nums.size(); j++)
//             {
//                 tmp = abs(nums[j] - crnt_val);
//                 if (crnt_min > tmp)
//                 {
//                     if (used.contains(i))
//                     {
//                         if (used[i] > tmp)
//                         {
//                             remove_v(diffs, used[i]);
//                             crnt_min = tmp;
//                             used[i] = tmp;
//                         }
//                     }
//                     else if (used.contains(j))
//                     {
//                         if (used[j] > tmp)
//                         {
//                             remove_v(diffs, used[j]);
//                             crnt_min = tmp;
//                             used[j] = tmp;
//                         }
//                     }
//                     else
//                     {
//                         crnt_min = tmp;
//                     }
//                 }
//             }

//             if (crnt_min == numeric_limits<int>::max())
//             {
//                 diffs.push_back(crnt_min);
//                 j = diffs.size() - 1;

//                 while (j > 0 && diffs[j - 1] > crnt_min)
//                 {
//                     diffs[j] = diffs[j - 1];
//                     --j;
//                 }

//                 diffs[j] = crnt_min;
//                 used[i] = crnt_min;
//             }
//         }

//         return diffs[p - 1];
//     }

//     void remove_v(vector<int>& nums, int val){
//         for(int i = 0; i < nums.size(); i++){
//             if(nums[i] == val){
//                 nums.erase(nums.begin() + i);
//                 return;
//             }
//         }
//     }
// };

class Solution
{
public:
    int minimizeMax(vector<int> &nums, int p)
    {
        if(p == 0){
            return 0;
        }
        vector<int> diffs;
        int crnt_min, crnt_val, tmp, j;
        int* used = new int[nums.size()];

        for (int i = 0; i < nums.size() - 1; i++)
        {
            crnt_val = nums[i];
            crnt_min = numeric_limits<int>::max();

            for (j = i + 1; j < nums.size(); j++)
            {
                tmp = abs(nums[j] - crnt_val);
                if (crnt_min > tmp)
                {
                    crnt_min = tmp;
                }
            }

            diffs.push_back(crnt_min);
            j = diffs.size() - 1;

            while (j > 0 && diffs[j - 1] > crnt_min)
            {
                diffs[j] = diffs[j - 1];
                --j;
            }

            diffs[j] = crnt_min;
        }

        return diffs[p - 1];
    }
};

int main()
{
    Solution s;

    vector<int> t1{3,4,2,3,2,1,2};

    cout << s.minimizeMax(t1, 3) << endl;
}