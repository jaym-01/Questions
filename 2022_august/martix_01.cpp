#include <iostream>
#include <vector>
#include <queue> 

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        queue<int*> next;

        for(int j = 0; j < mat.size(); j++){
            for(int i = 0; i < mat[0].size(); i++){
                if(mat[j][i] == 0){
                    next.push(new int[3]{i, j, 0});
                }
                else{
                    mat[j][i] = INT_MAX;
                }
            }
        }

        while(!next.empty()){
            fill(next.front()[0], next.front()[1], next.front()[2], mat, next);
            next.pop();
        }

        return mat;
    }

    void fill(int x, int y, int d, vector<vector<int>>& mat, queue<int*>& next){
        // check left, right, up and down -> if it changes - push to queue
        d++;
        // right
        if(x + 1 < mat[0].size() && mat[y][x + 1] > d){
            mat[y][x+1] = d;
            next.push(new int[3]{x+1, y, d});
        }

        // down
        if(y + 1 < mat.size() && mat[y + 1][x] > d){
            mat[y+1][x] = d;
            next.push(new int[3]{x, y+1, d});
        }

        // left
        if(x - 1 > -1 && mat[y][x - 1] > d){
            mat[y][x-1] = d;
            next.push(new int[3]{x-1, y, d});
        }

        // up
        if(y - 1 > -1 && mat[y - 1][x] > d){
            mat[y-1][x] = d;
            next.push(new int[3]{x, y-1, d});
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