#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits.h>
#include <set>

using namespace std;

// class Solution
// {
// public:
//     vector<vector<int>> threeSum(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());

//         int searching, idx, prev;
//         vector<vector<int>> out;

//         for (int i = 0; i < nums.size() - 2; i++)
//         {
//             prev = nums[i];
//             while(i < nums.size() - 2 && nums[i] == prev) i++;
//             --i;

//             for (int j = i + 1; j < nums.size() - 1; j++)
//             {
//                 prev = nums[j];
//                 while(j < nums.size() - 1 && nums[j] == prev) j++;
//                 --j;

//                 searching = -(nums[i] + nums[j]);
//                 if(bs(nums, j + 1, nums.size() - 1, searching) != -1){
//                     out.push_back(vector<int>({nums[i], nums[j], searching}));
//                 }                
//             }
//         }

//         return out;
//     }

//     int bs(vector<int>& nums, int start, int end, int t){
//         if(start > end) return -1;
//         else{
//             int mid = (start + end + 1) / 2;
//             if(t == nums[mid]) return mid;
//             else if(nums[mid] > t) return bs(nums, start, mid - 1, t);
//             else return bs(nums, mid + 1, end, t);
//         }
//     }
// };

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int start, end, sum;
        vector<vector<int>> out;
        set<vector<int>> mem;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++){
            if(nums[i] > 0) break;

            start = i + 1;
            end = nums.size() - 1;

            while(start < end){
                sum = nums[i] + nums[start] + nums[end];
                if(sum == 0){
                    mem.insert(vector<int>({nums[i], nums[start], nums[end]}));
                    start++;
                    --end;
                }
                else if(sum > 0) --end;
                else start++;
            }
        }

        for(auto i: mem){
            out.push_back(i);
        }

        return out;
    }
};

int main(){
    Solution s;

    vector<int> t1 = {-1, -1, 0, 1, -1, 2};
    vector<int> t2 = {0, 0,0};
    auto res = s.threeSum(t1);

    for(vector<int> l : res){
        for(int i: l){
            cout << i << ", ";
        }

        cout << endl;
    }
}