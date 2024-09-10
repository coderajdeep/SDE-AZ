// Implement stack using queue -- leetcode 225

// Implement stack using two queue
class MyStack {
private:
    queue<int> q1, q2;
    int element;
    // Time complexity O(n)
    void clearQueue(queue<int> &q) {
        while(!q.empty()) {
            q.pop();
        }
    }
public:
    // Time complexity O(n) 
    MyStack() {
        clearQueue(q1);
        // q2 is already empty
        clearQueue(q2);
    }
    // Time complexity O(n)
    void push(int x) {
        q2.push(x);
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    // Time complexity O(1)
    int pop() {
        element = q1.front();
        q1.pop();
        return element;
    }
    // Time complexity O(1)
    int top() {
        return q1.front();
    }
    // Time complexity O(1)
    bool empty() {
        return q1.empty();
    }
};

// Implement stack using single queue
class MyStack {
private:
    queue<int>q;
    int element, size;
    // Time complexity O(n)
    void clearQueue() {
        while(!q.empty()) {
            q.pop();
        }
    }
public:
    MyStack() {
        this->clearQueue();
    }
    // Time complexity O(n)
    void push(int x) {
        this->q.push(x);
        this->size = this->q.size();
        for(int i=0; i<(this->size-1); ++i) {
            this->q.push(this->q.front());
            this->q.pop();
        }
    }
    // Time complexity O(1)
    int pop() {
        if(this->q.empty()) {
            return -1;
        }
        this->element = this->q.front();
        this->q.pop();
        return this->element;
    }
    // Time complexity O(1)
    int top() {
        if(this->q.empty()) {
            return -1;
        }
        return this->q.front();
    }
    // Time complexity O(1)
    bool empty() {
        return this->q.empty();
    }
};