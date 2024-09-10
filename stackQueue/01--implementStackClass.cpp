// Implement stack class -- coding ninjas

// Stack class.
class Stack {
    
private:
    int topIndex;
    int *arr;
    int cap;
    
public:
    
    Stack(int capacity) {
        this->cap = capacity;
        this->topIndex = -1;
        this->arr = new int[this->cap];
    }

    void push(int num) {
        if(this->isFull()) {
            return;
        }
        this->topIndex += 1;
        this->arr[this->topIndex] = num;
    }

    int pop() {
        if(this->isEmpty()) {
            return -1;
        }
        int topElement = this->arr[this->topIndex];
        this->topIndex -= 1;
        return topElement;
    }
    
    int top() {
        if(this->isEmpty()) {
            return -1;
        }
        return this->arr[this->topIndex];
    }
    
    int isEmpty() {
        return (this->topIndex == -1);
    }
    
    int isFull() {
        return (this->cap == (this->topIndex+1));
    }
};
