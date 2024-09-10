// Insert at the begining of singly linkedlist -- coding ninja

/**
 * Definition of linked list
 * class Node {
 *
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 */
 
// Both are valid solutions
Node* insertAtFirst(Node* list, int newValue) {
    Node* root = new Node(newValue);
    if(list!=nullptr) {
        root->next = list;
    }
    return root;
}

Node* insertAtFirst(Node* list, int newValue) {
    Node* node = new Node(newValue);
    node->next = list;
    list = node;
    return list;
}