// Implement queue using stack -- leetcode 232

class MyQueue {
private:
    stack<int>s1, s2;
    int topElement;
    // Clear stack time complexity O(n)
    void clearStack(stack<int>&s) {
        while(!s.empty()) {
            s.pop();
        }
    }
public:
    MyQueue() {
        clearStack(s1);
        clearStack(s2);
    }
    //Push time complexity O(n)
    void push(int x) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    //Pop time complexity O(1)
    int pop() {
        if(s1.empty()) {
            return -1;
        }
        topElement = s1.top();
        s1.pop();
        return topElement;
    }
    //Peek time complexity O(1)
    int peek() {
        if(s1.empty()) {
            return -1;
        }
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

// Best approach
class MyQueue {
private:
    stack<int>input;
    stack<int>output;
    int topElement;
    // Clear stack time complexity O(n)
    void clearStack(stack<int>&s) {
        while(!s.empty()) s.pop();
    }
public:
    MyQueue() {
        clearStack(input);
        clearStack(output);
    }
    //Push time complexity O(1)
    void push(int x) {
        input.push(x);
    }
    // Time complexity θ(1) and O(n)
    int pop() {
        if(output.empty() && input.empty()) {
            return -1;
        }
        else if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        topElement = output.top();
        output.pop();
        return topElement;
    }
    // Time complexity θ(1) and O(n)
    int peek() {
        if(this->empty()) {
            return -1;
        }
        else if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return (input.empty() && output.empty());
    }
};