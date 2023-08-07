#include  <iostream>

using namespace std;

class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {

        // no repetitions possible => combinations factorial
        if(n == goal){
            int result = 0;

            while(n > 0){
                result *= n;
                --n;
            }

            return result;
        }


    }
};

int main(){
}