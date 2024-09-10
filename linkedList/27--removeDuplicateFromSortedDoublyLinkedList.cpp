// Remove duplicate nodes from sorted doubly linkedlist -- coding ninjas

// Time complexity O(n)
// Space complexity O(1)
Node * removeDuplicates(Node *head)
{
    if(!head || !head->next) return head;
    Node *curr = head;
    while(curr && curr->next) {
        if(curr->data == curr->next->data) {
            curr->next = curr->next->next;
            if(curr->next) {
                curr->next->prev = curr;
            }
        }
        else {
            curr = curr->next;
        }
    }
    return head;
}