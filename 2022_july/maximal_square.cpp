#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int max = 0;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] != '0' && matrix[i][j] != 'x'){
                    if(check_square(max + 1, i, j, matrix)){
                        max++;
                        while(check_expansion(max + 1, i, j, matrix)){
                            max++;
                        }
                    }
                    // while(check_square(max + 1, i, j, matrix)){
                    //     max++;
                    // }
                }
            }
        }

        return max * max;
    }

private:
    bool check_square(int size, int i, int j, vector<vector<char>>& matrix){
        if(size + i > matrix.size() || size + j > matrix[i].size()){
            return false;
        }

        for(int y = i; y < i + size; y++){
            for(int x = j; x < j + size; x++){
                if(matrix[y][x] == '0'){
                    return false;
                }
                else{
                    continue;
                }
            }
        }

        return true;
    }

    bool check_expansion(int size, int i, int j, vector<vector<char>>& matrix){
        // int x = j, y = i;

        if(size + i > matrix.size() || size + j > matrix[i].size()){
            return false;
        }
        
        signed int x = j + size - 1, y;

        for(y = i; y < i + size; y++){
            if(matrix[y][x] == '0'){
                return false;
            }
        }

        --y;

        for(; x > j - size + 1 && x >= 0; --x){
            if(matrix[y][x] == '0'){
                return false;
            }
            if(x < -1){
                cout << "x: " << x << "\ny:" << y << endl;
            }
        }

        return true;
    }
};

int main(){
    Solution s1;

    vector<vector<char>> test1 {{'1','1','1','1','0'},{'1','1','1','1','0'},{'1','1','1','1','1'},{'1','1','1','1','1'},{'0','0','1','1','1'}};

    cout << s1.maximalSquare(test1) << endl;
}