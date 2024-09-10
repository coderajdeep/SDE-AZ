// delete last of doubly linked list

/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() : data(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : data(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : data(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

Node * deleteLastNode(Node *head) {
    if(!head || !head->next) return nullptr;
    Node *prevNode = head, *curr = head;
    while(curr && curr->next) {
        prevNode = curr;
        curr = curr->next;
    }
    prevNode->next = nullptr;
    return head;
}
