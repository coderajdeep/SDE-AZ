// Implement stack class using Linkedlist -- coding ninjas

class Stack
{
    Node *top = nullptr;
    int size;

public:
    Stack()
    {
        this->size = 0;
        this->top = nullptr;
    }

    int getSize()
    {
        return (this->size);
    }

    bool isEmpty()
    {
        return (this->size == 0);
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        if(this->isEmpty()) {
            this->top = temp;
        }
        else {
            temp->next = this->top;
            this->top = temp;
        }
        this->size += 1;
    }

    void pop()
    {
        if(this->isEmpty()) {
            return;
        }
        Node *temp = this->top;
        this->top = temp->next;
        delete temp;
        this->size -= 1;
    }

    int getTop()
    {
        if(this->isEmpty()) {
            return -1;
        }
        return this->top->data;
    }
};