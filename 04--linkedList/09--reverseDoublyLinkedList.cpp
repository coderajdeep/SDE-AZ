// Reverse doubly linked list

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};

*/

// Time complexity O(n)
// Space complexity O(1)
Node* reverseDLL(Node* head)
{   
    Node *prev = nullptr;
    while(head) {
        head->prev = head->next;
        head->next = prev;
        prev = head;
        head = head->prev;
    }
    return prev;
}

