// Delete all the nodes equal to K in doubly linkedlist -- coding ninja

// Separately handling when when equals to k
// Time complexity O(n)
// Space complexity O(1)
Node * deleteAllOccurrences(Node* head, int k) {
    // if k is head
    while(head && head->data == k) {
        head = head->next;
    }
    if(!head) return nullptr;
    // without this should not work
    // test case is not proper
    // value wise there is no issue but head->prev should point to nullptr
    head->prev = nullptr;
    Node *curr = head;
    while(curr) {
        
        if(curr->data == k) {
            // curr can't be head so curr->prev always exist
            curr->prev->next = curr->next;
            // if curr is not the last node then only curr->next->prev exist
            if(curr->next) {
                curr->next->prev = curr->prev;
            }
        }
        curr = curr->next;
    }
    return head;
}

// Time complexity O(n)
// Space complexity O(1)
Node* deleteAllOccurrences(Node* head, int k) {
    Node* root = head;
    while(head) {
        if(head->data == k) {
            // if head is not the first element
            if(head->prev) {
                head->prev->next = head->next;
                // if head is not the last last element
                if(head->next) {
                    head->next->prev = head->prev;
                }
                head = head->next;
            }
            // head is the first elemnet
            else {
                head = head->next;
                root = head;
                // if head is not the last elemnt
                if(head) {
                    head->prev = nullptr;
                }
            }
        }
        else {
            head = head->next;
        }
    }
    return root;
}