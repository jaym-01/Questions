#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 1){
            return stoi(tokens[0]);
        }

        int total = 0, tmp;
        
        stack<int> operands;

        for(int i = 0; i < tokens.size(); i++){
            try{
                //it is just a number
                tmp = stoi(tokens[i]);

                operands.push(tmp); 
            }
            catch(exception e){
                //it is an operator -> perform the operation

                tmp = operands.top();
                operands.pop();

                total = getTotal(operands.top(), tmp, tokens[i]);
                operands.pop();

                operands.push(total);
            }
        }

        return total;

    }

private:
    int getTotal(int op1, int op2, string oprtr){
        if(oprtr == "+"){
            return op1 + op2;
        }
        else if(oprtr == "/"){
            return op1 / op2;
        }
        else if(oprtr == "*"){
            return op1 * op2;
        }
        else{
            return op1 - op2;
        }
    }
};

int main(){
    Solution s1;

    vector<string> test {"3","11","+","5","-"};
    vector<string> test1 {"4","13","5","/","+"};
    cout << s1.evalRPN(test1) << endl;
}