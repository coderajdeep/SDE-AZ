// Implement Minimum stack -- leetcode 155


// Time complexity O(1)
// Space complexity O(n)
// Best approach
class MinStack {
public:
    long minElement, topElement;
    stack<long> stk;
    MinStack() {
        // clearing stack
        while(!stk.empty()) {
            stk.pop();
        }
    }
    
    void push(int val) {
        if(stk.empty()) {
            minElement = val;
            stk.push(val);
        }
        else {
            if(val < minElement) {
                stk.push(2 * (long)val - minElement);
                minElement = val;
            }
            else {
                stk.push(val);
            }
        }
    }
    /*
    // this will also work
    void push(int val) {
        if(val < minElement) {
            stk.push(2*(long)val - minElement);
        }
        else {
            stk.push(val);
        }
        minElement = min(minElement, val);
    }
    */
    
    void pop() {
        if(stk.empty()) return;
        topElement = stk.top();
        if(topElement < minElement) {
            minElement = 2 * (long)minElement - topElement;
        }
        stk.pop();
    }
    
    int top() {
        if(stk.empty()) return -1;
        topElement = stk.top();
        if(topElement < minElement) return minElement;
        else return topElement;
    }
    
    int getMin() {
        return minElement;
    }
};

// Time complexity O(1)
// Space complexity O(2*n)
class MinStack {
private:
    // value, min 
    stack<pair<int, int>> stk;
    pair<int, int>p;
    void clearStack() {
        while(!stk.empty()) stk.pop();
    }
public:
    MinStack() {
        clearStack();
    }
    
    void push(int val) {
        if(stk.empty()) {
            stk.push({val, val});
        }
        else {
            p = stk.top();
            stk.push({val, min(val, p.second)});
        }
    }
    
    void pop() {
        if(!stk.empty()) {
            stk.pop();
        }
    }
    
    int top() {
        if(stk.empty()) {
            return -1;
        }
        else {
            p = stk.top();
            return p.first;
        }
    }
    
    int getMin() {
        if(stk.empty()) {
            return -1;
        }
        else {
            p = stk.top();
            return p.second;
        }
    }
};