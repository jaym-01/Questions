#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    bool isMatch(string s, string p) {
        int s_idx = 0;

        for(int i = 0; i < p.size(); i++){

            if(i != p.size() - 1 && p[i+1] == '*'){

                if(p.size() - i == 2 && p[i] == '.'){
                    return true;
                }

                while(s_idx < s.size() && (p[i] != '.' && s[s_idx] == p[i] || p[i] == '.')){

                    if(!isMatch(s.substr(s_idx, s.size() - s_idx), p.substr(i + 2, p.size() - i + 2))){
                        s_idx++;
                    }
                    else{
                        return true;
                    }
                }
                
                --s_idx;
                i++;
            }
            else if(p[i] != '.'){
                if(s[s_idx] != p[i]){
                    return false;
                }
            }
            else{
                if(s_idx >= s.size()){
                    return false;
                }
            }

            s_idx++;
        }

        if(s_idx < s.size()){
            return false;
        }

        return true;
    }
};

int main(){
    Solution sol;
    
    string s1 = "aa";
    string p1 = "aa.*";

    cout << sol.isMatch(s1, p1) << endl;

}