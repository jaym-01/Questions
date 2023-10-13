#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, int> str_map(string s){
        unordered_map<char, int> out;

        for(char c: s){
            if(out.find(c) != out.end()) out[c]++;
            else out[c] = 1;
        }

        return out;
    }

    bool check_all_zero(const unordered_map<char, int>& s_map){
        for(auto e: s_map){
            if(e.second != 0) return false;
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        unordered_map<char, int> s1_map = str_map(s1);

        int n = s1.size(), start = 0;

        // check first substring
        for(int i = start; i < n; i++){
            if(s1_map.find(s2[i]) != s1_map.end()) --s1_map[s2[i]];
        }
        
        if(check_all_zero(s1_map)) return true;
        start = 1;

        for(int i = start; i + n <= s2.size(); i++){
            if(s2[i - 1] == s2[i+n - 1]) continue;
            else{
                // now need previous one
                if(s1_map.find(s2[i - 1]) != s1_map.end()) s1_map[s2[i - 1]]++;

                // remove the next one added
                if(s1_map.find(s2[i + n - 1]) != s1_map.end()) --s1_map[s2[i+n-1]];

                if(check_all_zero(s1_map)) return true;
            }
        }

        return false;
    }
};

int main(){
    Solution s;

    cout << s.checkInclusion("sdjfvhdsfjhe", "sdjfehdsfjhv") << endl;
}