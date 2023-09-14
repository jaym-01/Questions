#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0, end, tmp;

        for(int i = 0; i < height.size(); i++){

            total += count(tmp = height[i], height, end = -1, i+1);

            i = end - 1;
        }

        return total;
    }

    int count(int& smallest, vector<int>& height, int& end_index, int current){
        if(current >= height.size()){
            end_index = height.size();
            return 0;
        }
        else if(height[current] >= smallest){
            end_index = current;
            return 0;
        }
        else if(current == height.size() - 1){
            smallest = height[current];
            end_index = current;
            return 0;
        }
        else{
            int total = count(smallest, height, end_index, current + 1);

            if(end_index == height.size() - 1 && height[current] >= smallest){
                smallest = height[current];
                return total;
            }

            total += smallest - height[current];
            return total;
        }
    }
};

int main(){
    Solution s;

    vector<int> t1 {4,2,0,3,2,5};

    cout << s.trap(t1) << endl;
}