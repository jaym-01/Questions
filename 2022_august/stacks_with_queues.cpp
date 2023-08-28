#include<iostream>
#include <queue>

using namespace std;

class MyStack {
private:

queue<int> contents;

public:
    MyStack() {}
    
    void push(int x) {
        queue<int> newq;
        newq.push(x);

        while(!contents.empty()){
            newq.push(contents.front());
            contents.pop();
        }

        contents = newq;
    }
    
    int pop() {
        int tmp = contents.front();

        contents.pop();

        return tmp;
    }
    
    int top() {
        return contents.front();
    }
    
    bool empty() {
        return contents.empty();
    }
};
