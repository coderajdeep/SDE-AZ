// Search in singly linked list

/****************************************************************

    Following is the class structure of the Node class:

    template <typename T>
    class Node
    {
    public:
        T data;
        Node<T> *next;
        Node()
        {
            this->data = 0;
            this->next = NULL;
        }
        Node(T data)
        {
            this->data = data;
            this->next = NULL;
        }
        Node(T data, T* next)
        {
            this->data = data;
            this->next = next;
        }
    };

*****************************************************************/

// Time complexity O(n)
// Space complexity O(1)
int searchInLinkedList(Node<int> *head, int k) {
    while(head) {
        if(head->data==k) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

// Recursive
// Time complexity O(n)
// Space complexity O(1) + recursive stack space O(n)
int searchInLinkedList(Node<int> *head, int k) {
    if(!head) return 0;
    if(head->data == k) return 1;
    return searchInLinkedList(head->next, k);
}