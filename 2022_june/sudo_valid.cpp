#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i, j;

        //check each row
        for(i = 0; i < 9; i++){

            map<char, bool> cols = map<char, bool>();
            map<char, bool> rows = map<char, bool>();

            for(j = 0; j < 9; j++){

                if(board[i][j] != '.' && (int)board[i][j] >= 1 && (int)board[i][j] <= 9){

                    pair row_out = cols.insert(pair<char, bool>(board[i][j], true));

                    if (!row_out.second){
                        return false;
                    }
                }
                else if(board[i][j] != '.'){
                    return false;
                }

                if(board[j][i] != '.' && (int)board[i][j] >= 1 && (int)board[i][j] <= 9){
                    
                }
            }
        }

        //check each column

        //check each 3X3 block

        return true;
    }
};