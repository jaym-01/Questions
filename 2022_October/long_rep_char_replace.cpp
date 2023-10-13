#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int maxFreq(const unordered_map<char, int>& freqs){
        int max = -1;

        for(auto e: freqs){
            if(e.second > max) max = e.second;
        }

        return max;
    }

    void addToMap(unordered_map<char, int>& freqs, char c){
        if(freqs.find(c) == freqs.end()){
            freqs[c] = 1;
        }
        else freqs[c]++;
    }

    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> freqs;
        int l = 0, r = 0, max = -1;
        
        while(r < s.size()){
            addToMap(freqs, s[r]);

            while(l <= r && r + 1 - l - maxFreq(freqs) > k){
                --freqs[s[l]];
                l++;
            }

            if(r + 1 - l > max) max = r + 1 - l;

            r++;
        }

        return max;
        
    }

    int characterReplacement1(string s, int k)
    {
        if (k >= s.size() - 1)
            return s.size();

        int swapped, max = -1, start;

        for (int i = 0; i < s.size(); i++)
        {
            swapped = 0;

            start = i;
            int j = i + 1;

            while (j < s.size() && swapped <= k)
            {
                if (s[j] != s[i])
                {
                    swapped++;
                }

                j++;
            }

            if (swapped > k)
                --j;
            else
            {

                while (start > 0 && swapped <= k)
                {
                    if (s[start - 1] != s[i])
                        swapped++;
                    --start;
                }

                if (swapped > k)
                    start++;
            }

            if (j - start > max)
                max = j - start;

            if (max == s.size())
                return max;
        }

        return max;
    }
};