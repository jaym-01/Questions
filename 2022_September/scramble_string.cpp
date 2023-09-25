#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;

        map<string, vector<string>> mem;

        vector<string> combos = scrambleCombos(s1, mem);

        for(string s: combos){
            if(s2 == s) return true;
        }

        return false;
    }

private:
    vector<string> scrambleCombos(string s, map<string, vector<string>>& mem){
        if(s.size() == 1) return vector<string>{s};
        else if (mem.contains(s)) {
            return mem[s];
        }
        else{
            string x, y;
            vector<string> x_combos, y_combos, out;
            int tmp_max;

            for(int i = 0; i < s.size() - 1; i++){
                x = s.substr(0, i+1);
                y = s.substr(i+1, s.size() - i - 1);

                x_combos = scrambleCombos(x, mem);
                y_combos = scrambleCombos(y, mem);

                for(int j = 0; j < x_combos.size(); j++){
                    for(int k = 0; k < y_combos.size(); k++){
                        out.push_back(x_combos[j] + y_combos[k]);
                        out.push_back(y_combos[k] + x_combos[j]);
                    }
                }
            }

            for(string out_val: out){
                mem[out_val] = out;
            }

            return out;
        }
    }
};

int main(){
    Solution s;
    cout << s.isScramble("great", "rgeat") << endl;
}