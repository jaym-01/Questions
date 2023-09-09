#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define iterate for(int i = 0; i < n; i++)

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<char> brackets;
        map<string, bool> mem;
        vector<string> out;

        iterate brackets.push_back('(');
        iterate brackets.push_back(')');

        all_combos(brackets, mem, "", out, true);

        return out;
    }

    void all_combos(vector<char> brackets, map<string, bool>& mem, string group, vector<string>& out, bool first){
        if(brackets.size() == 0){
            if(!mem.contains(group) && valid(group, mem)) out.push_back(group);
        }
        else if(mem.contains(group)){
            return;
        }
        else{
            int end;
            if(first) end = brackets.size() / 2;
            else end = brackets.size(); 

            for(int i = 0; i < end; i++){
                // partition vector
                vector<char> left = vector<char>(brackets.begin(), brackets.begin() + i), right = vector<char>(brackets.begin() + i + 1, brackets.end());
                
                left.insert(left.end(), right.begin(), right.end());

                all_combos(left, mem, group + brackets[i], out, false);
            }

            mem[group] = false;
        }
    }

    void all_combos_old(vector<char> brackets, map<string, bool>& mem, string group, vector<string>& out, bool first){
        if(brackets.size() == 0){
            if(!mem.contains(group) && valid(group, mem)) out.push_back(group);
        }
        else{
            int end;
            if(first) end = brackets.size() / 2;
            else end = brackets.size(); 

            for(int i = 0; i < end; i++){
                // partition vector
                vector<char> left = vector<char>(brackets.begin(), brackets.begin() + i), right = vector<char>(brackets.begin() + i + 1, brackets.end());
                
                left.insert(left.end(), right.begin(), right.end());

                all_combos(left, mem, group + brackets[i], out, false);
            }
        }
    }

    bool valid(string peths, map<string, bool>& mem){
        int opened = 0;
        
        for(int i = 0; i < peths.size(); i++){
            if(peths[i] == '(') opened++;
            else if(opened > 0) --opened;
            else return mem[peths] = false;
        }

        if(opened == 0) return mem[peths] = true;
        else return mem[peths] = false;
    }
};

int main(){
    Solution s;

    vector<string> out = s.generateParenthesis(8);

    for(int i = 0; i < out.size(); i++){
        cout << i << " | " << out[i] << endl;
    }
}