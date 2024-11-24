// Implement queue using linkedlist -- coding ninjas

Node *front = nullptr;
Node *rear = nullptr;

void Queue::push(int x) {
    Node *temp = new Node(x);
    if(front==nullptr) {
        front = rear = temp;
    }
    else {
        rear->next = temp;
        rear = temp;
    }
}

int Queue::pop() {
    if(front==nullptr) {
        return -1;
    }
    int frontElement = front->data;
    front = front->next;
    if(front==nullptr) {
        front = rear = nullptr;
    }
    return frontElement;
}