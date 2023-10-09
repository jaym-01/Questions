#include <iostream>
#include <unordered_map>
#include <string>
#include <limits.h>
#include <queue>
#include <utility>

using namespace std;

class Solution {
private:
    unordered_map<char, int> convert_unordered_map(string& t){
        unordered_map<char, int> out;

        for(char e: t){
            if(out.find(e) == out.end()) out[e] = 1;
            else out[e]++;
        }

        return out;
    }

    void remove_char(unordered_map<char, int>& t_unordered_map, unordered_map<char, int>::iterator it){
        if(it->second == 1) t_unordered_map.erase(it);
        else --it->second;
    }


public:
    string minWindow(string s, string t){
        unordered_map<char, int> t_map = convert_unordered_map(t), full_map;
        full_map = t_map;
        int start = 0, end = 0, start_out = -1, len = INT_MAX;
        
        while(end < s.size()){
            if(t_map.empty()){
                while(start < end && t_map.empty()){
                    if(full_map.find(s[start]) != full_map.end()) t_map[s[start]] = 1;
                    start++;
                }

                if(len > end - start - 1){
                    len = end - start - 1;
                    start_out = start - 1;
                }
            }
            else{
                auto it = t_map.find(s[end]);
                if(it != t_map.end()) remove_char(t_map, it);
                end++;
            }
        }

        if(start_out != -1) return s.substr(start_out, len);
        else return "";
    }

    string minWindow1(string s, string t) {
        if(t.size() > s.size()) return "";

        int start = -1, len = INT_MAX;
        unordered_map<char, int> t_unordered_map = convert_unordered_map(t), curr_unordered_map;

        for(int i = 0; i < s.size() - t.size() + 1; i++){
            if(t_unordered_map.find(s[i]) != t_unordered_map.end()){
                curr_unordered_map = t_unordered_map;
                int j = i;

                while(j < s.size() && !curr_unordered_map.empty()){
                    auto it = curr_unordered_map.find(s[j]);
                    if(it != curr_unordered_map.end()) remove_char(curr_unordered_map, it);
                    j++;
                }

                if(curr_unordered_map.empty() && j - i < len){
                    len = j - i;
                    start = i;
                }
                else if(!curr_unordered_map.empty()){
                    break;
                }
            }
        }

        if(start == -1) return "";
        else{
            return s.substr(start, len);
        }
    }
};

int main(){
    Solution s;

    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
}