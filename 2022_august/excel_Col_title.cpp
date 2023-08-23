#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        int tmp;
        string out = "";

        while (columnNumber > 0){
            tmp = columnNumber % 26 + 64;
            columnNumber = columnNumber / 26;
            if(tmp == 64){
                out = "Z" + out;
                --columnNumber;
            }
            else out = char(tmp) + out;
        }

        return out;
    }
};

int main(){
    Solution s;

    cout << s.convertToTitle(26) << endl;
}