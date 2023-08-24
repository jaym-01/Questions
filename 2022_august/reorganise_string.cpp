#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define assign prevchar = out[out.size() - 1]

class Solution
{
public:
    string reorganizeString(string s)
    {
        string out = "", left, right;
        char prevchar = ' ';
        int i;
        stack<char> rep;

        for (i = 0; i < s.size(); i++)
        {
            if (s[i] == prevchar)
                rep.push(s[i]);
            else
            {
                out = out + s[i];
                assign;

                while (!rep.empty() && rep.top() != prevchar)
                {
                    out = out + rep.top();
                    assign;
                    rep.pop();
                }
            }
        }

        i = 0;

        while (!rep.empty())
        {
            if (rep.top() != prevchar)
            {
                out = out + rep.top();
                assign;
                rep.pop();
            }
            else
            {
                if (rep.top() != out[0])
                {
                    out = rep.top() + out;
                    rep.pop();
                }
                else
                {
                    for (i = 0; i < out.size() - 1; i++)
                    {
                        if (out[i] != rep.top() && out[i + 1] != rep.top())
                        {
                            left = out.substr(0, i + 1);
                            right = out.substr(i + 1, out.size() - i - 1);
                            out = left + rep.top() + right;
                            rep.pop();
                            break;
                        }
                    }

                    if (i == out.size() - 1)
                    {
                        return "";
                    }
                }
            }
        }

        return out;
    }
};

int main()
{
    Solution s;

    cout << s.reorganizeString("cxmwmmm") << endl;
}