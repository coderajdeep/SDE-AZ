// Find where the loop begin in linkedlist -- leetcode 142

// Time complexity O(n)
// Space complexity O(n)
// Using unordered_set
ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode*>hashNode;
    while(head) {
        if(hashNode.find(head) != hashNode.end()) {
            return head;
        }
        hashNode.insert(head);
        head = head->next;
    }
    return nullptr;
}

// Time complexity O(n)
// Space complexity O(1)
// Slow and fast pointer approach
// Intuition : Lets say, slow is in the starting point in the loop and siatance covered is l
// then fast will be at distance l from slow
// lets say, distance from fast to slow is d
// So when fast and slow meet, distance covered by slow is d
// so from meeting point to loop starting distance is (l+d)-d = l
// Hence if start starts from head and fast starts from meeting point and 
// they cover 1 nood at a time then they will meet at the starting point of loop
ListNode* hasCycle(ListNode *head) {
    if(!head || !head->next) {
        return nullptr;
    }
    ListNode *slow = head, *fast = head;
    // Even when number of nodes is one or two
    // This will be handled with below logic
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) {
            return fast;
        }
    }
    return nullptr;
}

ListNode *detectCycle(ListNode *head) {
    ListNode *fast = hasCycle(head);
    if(!fast) {
        return nullptr;
    }
    ListNode *slow = head;
    while(slow!=fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// Time complexity O(n)
// Space complexity O(1)
// same solution as above
ListNode *detectCycle(ListNode *head) {
    if(!head || !head->next) return nullptr;
    ListNode *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}