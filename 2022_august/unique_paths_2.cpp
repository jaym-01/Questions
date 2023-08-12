#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1){
            return 0;
        }

        return traverse(obstacleGrid, 0, 0);
    }

    int traverse(vector<vector<int>>& matrix, int x, int y){
        if(y >= matrix.size() || x >= matrix[y].size()){
            return 0;
        }
        else if(x == matrix[y].size() - 1 && y == matrix.size() - 1){
            return 1;
        }
        else if(matrix[y][x] == 1){
            return 0;
        }
        else if(matrix[y][x] == 0){
            int paths = 0;

            paths += traverse(matrix, x + 1, y);
            paths += traverse(matrix, x, y + 1);

            matrix[y][x] = paths + 1;

            return paths;
        }
        else{
            return matrix[y][x] - 1;
        }
    }
};

int main(){
    Solution s;

    vector<vector<int>> t1 {{0,0,0},{0,0,0},{0,0,1}};

    cout << s.uniquePathsWithObstacles(t1) << endl;
}