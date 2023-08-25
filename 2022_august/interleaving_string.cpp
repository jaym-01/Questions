#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> mem = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return cut(s1, s2, s3, 0, 0, mem);
    }

private:
    bool cut(string s1, string s2, string s3, int n, int m, vector<vector<int>> mem){
        if(s1 == "" && s2 == "" && s3 == "" && abs(n - m) <= 1){
            return true;
        }
        else if(s1.size() + s2.size() != s3.size()){
            return false;
        }
        else if(mem[s1.size()][s2.size()] != -1){
            return mem[s1.size()][s2.size()];
        }

        int i = 0;
        bool result;

        if(s1.size() > 0 && s1[0] == s3[0]){
            while(i < s1.size() && s1[i] == s3[i]) i++;

            result = false;

            while(i > 0){
                if(s2.size() == 0 || (s2.size() > 0 && i < s3.size() && s2[0] == s3[i])){
                    result = cut(s1.substr(i, s1.size() - i), s2, s3.substr(i, s3.size() - i), n + 1, m, mem);
                    if(result) return true;
                }
                mem[s1.size() - i][s2.size()] = result;
                --i;
            }
        }

        i = 0;
        if(s2.size() > 0 && s2[0] == s3[0]){
            while(i < s2.size() && s2[i] == s3[i]) i++;

            result = false;

            while(i > 0){
                if(s1.size() == 0 || (s1.size() > 0 && i < s3.size() && s1[0] == s3[i])){
                    result = cut(s1, s2.substr(i, s2.size() - i), s3.substr(i, s3.size() - i), n, m + 1, mem);
                    if(result) return true;
                }
                mem[s1.size()][s2.size() - i] = result;
                --i;
            }
        }

        mem[s1.size()][s2.size()] = false;
        return false;
    }
};

int main(){
    Solution s;

    cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
}