#include "iostream"
#include "vector"
#include "limits.h"
#include "stack"

using namespace std;

class Solution
{
private:
    void compute_areas(stack<pair<int, int>>& s, int i, int& max, int curr_val){
        int start = -1, tmp_area;
        
        while((curr_val == -1 && !s.empty()) || (curr_val != -1 && !s.empty() && s.top().second > curr_val)){
            start = s.top().first;

            tmp_area = (i - start)*s.top().second;

            if(tmp_area > max) max = tmp_area;

            s.pop();            
        }

        if(curr_val != -1 && start != -1) s.push(pair<int, int>(start, curr_val));
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        // index | val
        stack<pair<int, int>> s;
        int max_area = INT_MIN;

        for (int i = 0; i < heights.size(); i++)
        {
            if (!s.empty() && s.top().second == heights[i]){
                continue;
            }
            else if (!s.empty() && s.top().second > heights[i])
            {
                compute_areas(s, i, max_area, heights[i]);
            }
            else{
                s.push(pair<int, int>(i, heights[i]));
            }
        }

        compute_areas(s, heights.size(), max_area, -1);

        return max_area;
    }
};

int main()
{
    Solution s;

    vector<int> t1 = {2,1,5,6,2,3};

    cout << s.largestRectangleArea(t1) << endl;
}