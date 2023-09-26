#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class data_struct{
public:
    string s;
    int start;
    int end;

    data_struct(string s_i, int start_i, int end_i): s(s_i), start(start_i), end(end_i) {}
};

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;

        map<data_struct, bool> mem;
        return solve(s1, s2, 0, s2.size() - 1, mem);
    }

private:
    bool solve(string s, string s2, int start, int end, map<data_struct, bool>& mem){
        if(mem.contains(data_struct(s, start, end))) {
            return mem[data_struct(s, start, end)];
        }
        else if(s.size() == 1 && s2[start] == s[0]) return true;
        else if(s.size() == 1) return false;
        else{
            string left, right;

            for(int i = 0; i < s.size() - 1; i++){
                left = s.substr(0, i+1);
                right = s.substr(i + 1, s.size() - i - 1);

                mem[data_struct(left, start, i)] = solve(left, s2, start, i, mem);
                mem[data_struct(right, i + 1, end)] = solve(right, s2, i + 1, end, mem);

                mem[data_struct(right, start, start + right.size() - 1)] = solve(right, s2, start, start + right.size() - 1, mem);
                mem[data_struct(left, end - left.size() + 1, end)] = solve(left, s2, end - left.size() + 1, end, mem);

                if(mem[data_struct(left, start, i)] && mem[data_struct(right, i + 1, end)]) return true;
                else if(mem[data_struct(right, start, start + right.size() - 1)] && mem[data_struct(left, end - left.size() + 1, end)]) return true;
            }

            return false;
        }
    }
};

int main(){
    Solution s;
    cout << s.isScramble("qwertyuiopasdfghjklzxcvbnm", "asdfghjklzxcvbnmqwertyuiop") << endl;
}