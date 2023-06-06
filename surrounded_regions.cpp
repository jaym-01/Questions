#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board[0].size(); i++){
            for(int j = 0; j < board.size(); j++){
                check_0(board, i, j);
            }
        }
    }

private:
    
    bool check_0(vector<vector<char>>& board, int i, int j){
        
        if(board[j][i] != 'X' && board[j][i] != '1'){

            if(j == 0 || i == 0 || j == board.size() - 1 || i == board[j].size() - 1){
                
                return false;
            }

            //at 0 -> change to 1 -> show it is visited
            board[j][i] = '1';

            bool out = true, tmp;

            //check other elements in all other directions
            if(j > 0){
                tmp = check_0(board, i, j - 1);
                if(out){
                    out = tmp;
                }
            }
            if(i > 0){
                tmp = check_0(board, i - 1, j);
                if(out){
                    out = tmp;
                }
            }
            if(i < board[j].size() - 1){
                tmp = check_0(board, i + 1, j);
                if(out){
                    out = tmp;
                }
            }
            if(j < board.size()){
                tmp = check_0(board, i, j + 1);
                if(out){
                    out = tmp;
                }
            }

            if(out){
                board[j][i] = 'X';
            }
            else{
                board[j][i] = 'O';
            }

            return out;

        }

        return true;

    }
};

int main(){
    Solution s1;
    vector<vector<char>> board{
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    s1.solve(board);

    for(int j = 0; j < board.size(); j++){
        for(int i = 0; i < board[j].size(); i++){
            cout << board[j][i] << " ";
        }
        cout << endl;
    }

}