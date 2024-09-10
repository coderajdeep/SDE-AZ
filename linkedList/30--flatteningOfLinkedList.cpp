// Flattening of linkedlist -- Coding Ninjas
// Time complexity O(k*n*n)
// Space complexity O(1)
Node* merge2List(Node *l1, Node *l2) {
    Node *dummy = new Node(0);
    Node *newHead = dummy;
    while(l1 && l2) {
        if(l1->data < l2->data) {
            dummy->child = l1;
            l1 = l1->child;
        }
        else {
            dummy->child = l2;
            l2 = l2->child;
        }
        dummy = dummy->child;
    }
    if(l1) dummy->child = l1;
    if(l2) dummy->child = l2;
    return newHead->child;
}
Node* flattenLinkedList(Node* head) 
{
    if(!head || !head->next) return head;
    Node *curr = head, *prev = head;
    curr = curr->next;
    while(curr) {
        prev = merge2List(prev, curr);
        curr = curr->next;
    }
    return prev;
}

// Best approach
// Using Min Heap
// Time complexity O(mlogm) where m = n*k
// Space complexity O(m) where m = n*k
Node* flattenLinkedList(Node* head) 
{
	priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> minHeap;
    Node *curr = head;
    while(curr) {
        minHeap.push(pair<int, Node*> {curr->data, curr});
        curr = curr->next;
    }
    Node *dummy = new Node(0);
    Node *newHead = dummy;
    while(!minHeap.empty()) {
        pair<int, Node*> p = minHeap.top();
        minHeap.pop();
        Node *node = p.second;
        dummy->child = node;
        dummy = dummy->child;
        if(dummy->child) {
            minHeap.push(pair<int, Node*> {dummy->child->data, dummy->child});
        }
    }
    return newHead->child;
}