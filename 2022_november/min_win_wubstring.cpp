#include "iostream"
#include "string"
#include "unordered_map"
#include "limits.h"

using namespace std;

class Solution {
public:
    void shrink(const string& s, unordered_map<char, int>& tls, int& l, const int& r){
        while(l <= r){
            if(tls.count(s[l]) == 1){
                if(tls[s[l]] < 0){
                    tls[s[l]]++;
                }
                else{
                    return;
                }
            }

            l++;
        }
    }

    unordered_map<char, int> t_to_map(const string& t){
        unordered_map<char, int> out;

        for(char c: t){
            if(out.count(c) == 0) out[c] = 1;
            else out[c]++;
        }

        return out;
    }

    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        int n = t.size(), l = 0, r = 0, lm = 0, rm = INT_MAX - 100;

        unordered_map<char, int> tls = t_to_map(t);

        for(; r < s.size(); r++){
            if(tls.count(s[r]) == 1){
                if(tls[s[r]] > 0) --n;
                --tls[s[r]];

                if(n <= 0){
                    shrink(s, tls, l, r);

                    if(r - l < rm - lm){
                        lm = l;
                        rm = r;
                    }
                }
            }
        }

        if(n > 0) return "";
        return s.substr(lm, rm - lm + 1);
    }
};

int main(){
    Solution s;

    cout << s.minWindow("", "ABCDEF") << endl;
}