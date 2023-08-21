#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size() / 2;
        string sub;
        bool worked;

        while(len > 0){
            if(s.size() % len == 0){
                sub = s.substr(0, len);

                worked = true;

                for(int j = 0; j + len <= s.size(); j += len){
                    if(s.substr(j, len) != sub){
                        worked = false;
                    }
                }

                if (worked) return true;
            }

            --len;
        }

        return false;
    }
};

int main(){
    Solution s;

    string test = "aba";

    cout << s.repeatedSubstringPattern(test) << endl;

}