#include <iostream>
#include <vector>

using namespace std;

#define check i < nums1.size() && j < nums2.size()

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;

        int j = 0, i = 0;

        while(check){
            while(check && nums2[j] <= nums1[i]){
                merged.push_back(nums2[j]);
                j++;
            }
            
            while(check && nums1[i] < nums2[j]){
                merged.push_back(nums1[i]);
                i++;
            }
        }

        while(i < nums1.size()){
            merged.push_back(nums1[i]);
            i++;
        }

        while(j < nums2.size()){
            merged.push_back(nums2[j]);
            j++;
        }

        if(merged.size() % 2 == 0){
            int mid = merged.size() / 2;
            return (merged[mid] + merged[mid - 1]) / 2.0;
        }
        else{
            return merged[(int)(merged.size() / 2)];
        }
    }
};
int main(){
    Solution s1;

    vector<int> in1 {1, 3};

    vector<int> in2 {2};

    cout << s1.findMedianSortedArrays(in1, in2) << endl;
}