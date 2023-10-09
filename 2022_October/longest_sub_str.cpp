#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() < 2) return s.size();

        unordered_map<char, bool> substr_contents;

        int max = -1, j; 

        for(int i = 0; i < s.size(); i++){
            while(i < s.size() - 1 && s[i] == s[i + 1]){
                i++;
            }

            j = i;
            substr_contents.clear();

            while(j < s.size() && substr_contents.find(s[j]) == substr_contents.end()){
                substr_contents[s[j]] = true;
                j++;
            }

            if(j - i > max) max = j - i;
        }

        return max;
    }
};

int main(){
    Solution s;

    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
}