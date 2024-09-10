// Copy a linkedlist which have a next and random pointer -- leetcode 138
// Time complexity O(n)
// Space complexity O(n)
Node* copyRandomList(Node* head) {
    if(!head) return nullptr;
    unordered_map<Node*, Node*> nodeHash;
    Node *dummy = new Node(0);
    Node *curr = head, *newHead = dummy;
    while(curr) {
        Node *node = new Node(curr->val);
        nodeHash[curr] = node;
        dummy->next = node;
        dummy = dummy->next;
        curr = curr->next;
    }
    curr = head;
    while(curr) {
        Node *node = nodeHash[curr];
        Node *randomNode = nodeHash[curr->random];
        node->random = randomNode;
        curr = curr->next;
    }
    return newHead->next;
}