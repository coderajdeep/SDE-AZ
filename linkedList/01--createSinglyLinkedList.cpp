// Create a singly linkedlist from vector -- coding ninja

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

Node* constructLL(vector<int>& arr) {
    int n = arr.size();
    if(n==0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for(int i=1; i<n; ++i) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}