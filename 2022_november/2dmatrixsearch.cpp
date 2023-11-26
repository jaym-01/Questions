#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size(), start = 0, end = (n*m) - 1;

        int r_mid, c_mid, mid;

        while(start <= end){
            mid = (start + end) / 2;
            r_mid = mid / n;
            c_mid = mid % n;

            if(matrix[r_mid][c_mid] == target) return true;
            else if(matrix[r_mid][c_mid] > target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        return false;
    }
};