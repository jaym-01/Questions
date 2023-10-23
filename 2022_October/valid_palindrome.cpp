#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    char convertLowerCase(char c){
        int ac = (int)c;

        if(ac > 64 && ac < 91) return char(ac+32);        
        else if(ac > 96 && ac < 123 || ac > 47 && ac < 58) return c;
        else return '?';
    }

public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        char curr_i, curr_j;

        while(i < j){
            curr_i = convertLowerCase(s[i]);
            curr_j = convertLowerCase(s[j]);

            while(i < j && curr_i == '?'){
                i++;
                curr_i = convertLowerCase(s[i]);
            }

            while(i < j && curr_j == '?'){
                --j;
                curr_j = convertLowerCase(s[j]);
            }

            if(i < j && curr_i != curr_j) return false;
            else{
                i++;
                --j;
            }
        }

        return true;
    }
};

int main(){
    Solution s;

    cout << s.isPalindrome("0P") << endl;

}