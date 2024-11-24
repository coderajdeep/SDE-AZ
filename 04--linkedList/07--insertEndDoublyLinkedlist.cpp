/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int value;
 *      Node *prev;
 *      Node *next;
 *      Node() : value(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : value(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : value(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

Node * insertAtTail(Node *head, int k) {
    Node* node = new Node(k);
    if(!head || !head->next) return node;
    Node* prevNode = head;
    Node* curr = head;
    while(curr && curr->next) {
        prevNode = curr;
        curr = curr->next;
    }
    curr->next = node;
    node->prev = curr;
    return head;
}
