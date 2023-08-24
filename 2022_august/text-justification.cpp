#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> lines;
        int min_count = -1;
        string line;
        queue<string> qu;

        for(int i = 0; i < words.size(); i++){
            min_count += words[i].size() + 1;
            qu.push(words[i]);

            if(min_count > maxWidth){
                line = create_line(qu, min_count - words[i].size() + 1 - qu.size(), maxWidth,  qu.size() - 2);
                lines.push_back(line);

                min_count = words[i].size();
            }
        }

        if(qu.size() == 1){
            int gap_size = maxWidth - qu.front().size();
            string gap(gap_size, ' ');
            lines.push_back(qu.front() + gap);
            qu.pop();
        }
        else{
            line = "";
            while(!qu.empty()){
                line = line + qu.front();
                qu.pop();
                if(qu.empty()){
                    string tmp(maxWidth - line.size(), ' ');
                    line = line + tmp;
                }
                else{
                    line = line + " ";
                }
            }

            lines.push_back(line);
        }

        return lines;
    }

    string create_line(queue<string>& qu, int wrds_count, int maxWidth, int gaps){
        //only 1 word on a line
        if(gaps == 0){
            if(qu.front().size() == maxWidth){
                string tmp = qu.front();
                qu.pop();
                return tmp;
            }
            else{
                string gap(maxWidth - qu.front().size(), ' ');
                string tmp = qu.front() + gap;
                qu.pop();
                return tmp;
            }
        }

        int ttl_gap_size = maxWidth - wrds_count, gap_size = ttl_gap_size / gaps, extra = ttl_gap_size % gaps;

        string line = "", gap(gap_size, ' ');

        while(qu.size() > 2){
            line = line + qu.front();
            qu.pop();

            if(qu.size() != 0){
                line = line + gap;
                if(extra > 0){
                    line = line + " ";
                    --extra;
                }
            }
        }

        if(qu.size() > 0){
            line = line + qu.front();
            qu.pop();
        }

        return line;
    }
};

int main(){
    Solution s;

    vector<string> t1 {"What","must","be","acknowledgment","shall","be"};

    vector<string> out = s.fullJustify(t1, 16);

    for(int i = 0; i < out.size(); i++){
        cout << "|" << out[i] << "|" << endl;
    }
}