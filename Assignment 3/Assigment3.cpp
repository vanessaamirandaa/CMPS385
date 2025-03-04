//
//  main.cpp
//  CMPS 385
//
//  Created by Vanessa Miranda on 03/04/25.
//

#include <iostream>
#include <stack>

using namespace std;

typedef stack<int> Stack;

// Push function
int push(int T, Stack &s) {
    s.push(T);
    return T;
}

// Top and Pop function
int topandpop(Stack &s) {
    if (s.empty()) {
        cout << "Stack is empty!" << endl;
        return -1; // Return an error code
    }
    int topElement = s.top();
    s.pop();
    return topElement;
}

int main() {
    Stack s;
    
    push(10, s);
    push(20, s);
    push(30, s);
    
    cout << "Top and Pop: " << topandpop(s) << endl;
    cout << "Top and Pop: " << topandpop(s) << endl;
    cout << "Top and Pop: " << topandpop(s) << endl;
    cout << "Top and Pop: " << topandpop(s) << endl; // This will show stack is empty
    
    return 0;
}
