#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
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

                if(swapped > k)
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