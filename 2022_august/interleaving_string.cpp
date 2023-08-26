#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }

        vector<vector<bool>> mem = vector<vector<bool>>(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        
        //the empty s1 and empty s2 are both the same as the empty s3
        //also need it to work for the algorithm
        mem[0][0] = true;

        // How much of the start of s1 is the same as s3 - once its different - the rest of s1 combinations become false
        for(int i = 1; i < s1.size(); i++){
            mem[i][0] = mem[i-1][0] && s1[i-1] == s3[i-1];
        }

        // same for s2
        for(int j = 1; j < s2.size(); j++){
            mem[0][j] = mem[0][j-1] && s2[j-1] == s3[j-1];
        }

        for(int i = 1; i <= s1.size(); i++){
            for(int j = 1; j <= s2.size(); j++){
                // checking for splits that could occur
                // checking the current index of s3 -> which is currently made up of  s1 and s2 -> but can be mixed up in any way

                mem[i][j] = (mem[i-1][j] && s1[i-1] == s3[i+j-1]) || (mem[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }

        return mem[s1.size()][s2.size()];
    }
};

int main(){
    Solution s;

    cout << s.isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa", "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab", "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab") << endl;
}