#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> out = vector<vector<int>>(mat.size(), vector<int>(mat[0].size(), -1));

        for(int j = 0; j < mat.size(); j++){
            for(int i = 0; i < mat[0].size(); i++){
                if(out[j][i] == -1){
                    shortest_path(mat, i, j, out);
                }
            }
        }

        return out;
    }

    int shortest_path(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& out){
        if(x < 0 || y < 0 || x >= matrix[0].size() || y >= matrix.size()){
            return INT_MAX - 2;
        }
        else if (out[y][x] != -1){
            return out[y][x];
        }
        else if(matrix[y][x] == 0){
            out[y][x] = 0;
            return 0;
        }
        else if(matrix[y][x] == -1){
            return INT_MAX - 2;
        }
        else{
            int og = matrix[y][x]; 
            matrix[y][x] = -1;

            int right = shortest_path(matrix, x + 1, y, out) + 1;
            int down = shortest_path(matrix, x, y + 1, out) + 1;
            int left = shortest_path(matrix, x - 1, y, out) + 1;
            int up = shortest_path(matrix, x, y - 1, out) + 1;

            int min, tmp;

            if(up < down) min = up;
            else min = down;

            if(left < right) tmp = left;
            else tmp = right;

            if(tmp < min) min = tmp;

            if(min == INT_MAX - 1) out[y][x] = -1;
            else out[y][x] = min;
            
            matrix[y][x] = og;
            return min;
        }
    }
};

int main(){
    Solution s;

    vector<vector<int>> t1 {{1,1,1},{1,1,1},{0,1,0}}, t2 {
    {0,0,1,0,1,1,1,0,1,1},
    {1,1,1,1,0,1,1,1,1,1},
    {1,1,1,1,1,0,0,0,1,1},
    {1,0,1,0,1,1,1,0,1,1},
    {0,0,1,1,1,0,1,1,1,1},
    {1,0,1,1,1,1,1,1,1,1},
    {1,1,1,1,0,1,0,1,0,1},
    {0,1,0,0,0,1,0,0,1,1},
    {1,1,1,0,1,1,0,1,0,1},
    {1,0,1,1,1,0,1,1,1,0}
};

    t1 = s.updateMatrix(t2);

    for(int j = 0; j < t1.size(); j++){
        for(int i = 0; i < t1[0].size(); i++){
            cout << t1[j][i] << ", ";
        }
        cout << endl;
    }
    
}