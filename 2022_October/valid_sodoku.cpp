#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    bool validRow(const vector<vector<char>> &board, int row)
    {
        bool spaces[10] = {0};

        for (int i = 0; i < board[row].size(); i++)
        {
            if (board[row][i] != '.')
            {
                if (spaces[(int)board[row][i] - 48])
                    return false;
                else
                    spaces[(int)board[row][i] - 48] = true;
            }
        }

        return true;
    }

    bool validCol(const vector<vector<char>> &board, int col)
    {
        bool spaces[10] = {0};

        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][col] != '.')
            {
                if (spaces[(int)board[i][col] - 48])
                    return false;
                else
                    spaces[(int)board[i][col] - 48] = true;
            }
        }

        return true;
    }

    bool valid33(const vector<vector<char>> &board, int i, int j)
    {
        bool spaces[10] = {0};

        for (int x; x < i + 3; x++)
        {
            for (int y = j; y < j + 3; y++)
            {
                if (board[y][x] != '.')
                {
                    if (spaces[(int)board[y][x] - 48])
                        return false;
                    else
                        spaces[(int)board[y][x] - 48] = true;
                }
            }
        }

        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            if (!(validRow(board, i) && validCol(board, i)))
                return false;
            if (i % 3 == 0)
            {
                if (!(valid33(board, 0, i) && valid33(board, 3, i) && valid33(board, 6, i)))
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;

    vector<vector<char>> t1

        {{'.', '.', '.', '.', '5', '.', '.', '1', '.'}, {'.', '4', '.', '3', '.', '.', '.', '.', '.'}, {'.', '.', '.', '.', '.', '3', '.', '.', '1'}, {'8', '.', '.', '.', '.', '.', '.', '2', '.'}, {'.', '.', '2', '.', '7', '.', '.', '.', '.'}, {'.', '1', '5', '.', '.', '.', '.', '.', '.'}, {'.', '.', '.', '.', '.', '2', '.', '.', '.'}, {'.', '2', '.', '9', '.', '.', '.', '.', '.'}, {'.', '.', '4', '.', '.', '.', '.', '.', '.'}};

    cout << s.isValidSudoku(t1) << endl;
}