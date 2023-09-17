#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(s == p) return true;

        vector<vector<int>> mem = vector<vector<int>>(s.size() + 1, vector<int>(p.size() + 1, -1));

        return traverse(s, 0, p, 0, mem);
    }

private:
    bool traverse(string& s, int s_i, string& p, int p_i, vector<vector<int>>& mem){
        if(mem[s_i][p_i] != -1) return mem[s_i][p_i];
        else if(s_i >= s.size()) {
            if(p.size() - p_i >= 0 && p.substr(p_i, p.size() - p_i) == string(p.size() - p_i, '*')) return true;
            else return false;
        }
        else if(p_i >= p.size()) return false;
        else{
            bool out = false;

            if(p[p_i] == '*'){

                //all the stars mean the same thing as 1 star - skips over them
                int new_p_i = p_i;
                while(new_p_i < p.size() && p[new_p_i] == '*'){
                    new_p_i++;
                }
                if(new_p_i != p_i) p_i = new_p_i - 1;

                // first try it if * is empty
                out = traverse(s, s_i, p, p_i + 1, mem);
                // mem[s_i][p_i] = out;

                while(s_i < s.size() && !out){
                    out = traverse(s, s_i + 1, p, p_i + 1, mem);
                    // mem[s_i][p_i] = out;
                    s_i++;
                }
            }
            else if(p[p_i] == s[s_i] || p[p_i] == '?') out = traverse(s, s_i + 1, p, p_i+1, mem);

            mem[s_i][p_i] = out;
            return out;
        }
    }
};

int main(){
    Solution s;

    cout << s.isMatch("bbbbbbbabbaabbabbbbaaabbabbabaaabbababbbabbbabaaabaab", "b*b*ab**ba*b**b***bba") << endl;
}