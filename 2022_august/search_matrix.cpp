#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), low = 0, high = (m*n) - 1, mid, i, j;

        while(!(high < low)){
            mid = (high + low)/2;
            i = mid % n;
            j = mid / n;

            if(matrix[j][i] == target){
                return true;
            }
            else if(matrix[j][i] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return false;
    }
};

int main(){
    Solution s1;
    vector<vector<int>> t1 {{1, 3}};

    cout << s1.searchMatrix(t1, 3) << endl;
}