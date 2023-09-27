#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        auto mem = vector<vector<vector<int>>>(s1.size(), vector<vector<int>>(s1.size(), vector<int>(s1.size() + 1, -1)));

        return solve(s1, s2, 0, 0, s1.size(), mem);
    }

private:
    bool solve(string& s1, string& s2, int i, int j, int len, vector<vector<vector<int>>>& mem){
        if(len == 1) return mem[i][j][len] = s1[i] == s2[j];
        else if(mem[i][j][len] != -1) return mem[i][j][len];
        else{
            for(int k = 1; k < len; k++){
                mem[i][j][k] = solve(s1, s2, i, j, k, mem);
                mem[i + k][j + k][len - k] = solve(s1, s2, i + k, j + k, len - k, mem);

                mem[i][j + len - k][k] = solve(s1, s2, i, j + len - k, k, mem);
                mem[i + k][j][len - k] = solve(s1, s2, i + k, j, len - k, mem);

                if(mem[i][j][k] && mem[i+k][j+k][len-k] || mem[i][j+len-k][k] && mem[i+k][j][len-k]) return true;
            }

            return false;
        }
    }
};

int main(){
    Solution s;
    cout << s.isScramble("abcde", "caebd") << endl;
}