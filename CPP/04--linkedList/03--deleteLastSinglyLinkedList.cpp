// Delete last node of singly linked list -- coding ninjas

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *deleteLast(Node *list){
    if(!list || !list->next) return nullptr;
    Node* curr = list;
    Node* prevNode = nullptr;
    while(curr && curr->next) {
        prevNode = curr;
        curr = curr->next;
    }
    prevNode->next = nullptr;
    return list;
}