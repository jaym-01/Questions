#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        return traverse(0, 0, grid);
    }

    //recursive check every path
    int traverse(int x, int y, vector<vector<int>>& grid){
        if(x < grid[0].size() && x > -1 && y < grid.size() && y > -1){

            int right = traverse(x+1, y, grid);
            int down = traverse(x, y + 1, grid);

            if(right == 0 && down == 0){
                return grid[y][x];
            }
            else if(right == 0){
                return grid[y][x] + down;
            }
            else if(down == 0){
                return grid[y][x] + right;
            }
            else if(right > down){
                return grid[y][x] + down;
            }
            else{
                return grid[y][x] + right;
            }
        }

        else{
            return 0;
        }
    }
};

int main(){
    Solution obj;

    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}}; 

    cout << obj.minPathSum(grid) << endl;
}