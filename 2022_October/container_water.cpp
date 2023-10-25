#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int areaCalc(int start, int end, vector<int>& height){
        int min_h = min(height[start], height[end]);

        return min_h * (end - start);
    }
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size() - 1, *smallest, max = -1, tmp, chg;

        while(start < end){
            tmp = areaCalc(start, end, height);

            if(tmp > max) max = tmp;

            tmp = min(height[start], height[end]);

            if(tmp == height[start]) {
                smallest = &start;
                chg = 1;
            }
            else {
                smallest = &end;
                chg = -1;
            }

            while(*smallest > -1 && *smallest < height.size() && tmp >= height[*smallest]){
                *smallest += chg;
            }
        }

        return max;
    }
};

int main(){
    Solution s;

    vector<int> t1 = {1,50,100,1};

    cout << s.maxArea(t1) << endl;
}