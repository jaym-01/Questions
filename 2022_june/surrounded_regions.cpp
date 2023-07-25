#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        outer_edge_check(board, 'O', '1');

        inner_region_capture(board);

        outer_edge_check(board, '1', 'O');
    }

private:

    void change_region(vector<vector<char>>& board, char og_val, char new_val, int i, int j){
        if(board[j][i] == og_val){
            board[j][i] = new_val;

            //check right -> down -> left -> up
            if(i < board[0].size() - 1){
                change_region(board, og_val, new_val, i + 1, j);
            }
            if(j < board.size() - 1){
                change_region(board, og_val, new_val, i, j + 1);
            }
            if(i > 0){
                change_region(board, og_val, new_val, i - 1, j);
            }
            if(j > 0){
                change_region(board, og_val, new_val, i, j - 1);
            }
        }

        return;
    }

    void outer_edge_check(vector<vector<char>>& board, char og_val, char new_val){
        for(int i = 0; i < board[0].size(); i += board[0].size() - 1){
            for(int j = 0; j < board.size(); j++){
                if(board[j][i] == og_val){
                    change_region(board, og_val, new_val, i, j);
                }
            }

            if(board[0].size() == 1){
                break;
            }
        }

        for(int j = 0; j < board.size(); j += board.size() - 1){
            for(int i = 0; i < board[0].size(); i++){
                if(board[j][i] == og_val){
                    change_region(board, og_val, new_val, i, j);
                }
            }

            if(board.size() == 1){
                break;
            }
        }
    }

    void inner_region_capture(vector<vector<char>>& board){
        
        for(int j = 1; j < board.size() - 1; j++){
            for(int i = 1; i < board[0].size() - 1; i++){
                if(board[j][i] == 'O'){
                    change_region(board, 'O', 'X', i, j);
                }
            }
        }
    }
};

int main(){
    Solution s1;

    vector<vector<char>> input {
        {'X'}
    };

    s1.solve(input);

    
    for(int j = 0; j < input.size(); j++){

        for(int i = 0; i < input[0].size(); i++){
            cout << input[j][i] << " ";
        }

        cout << endl;
    }
}