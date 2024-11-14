// Detect cycle in linkedlist -- leetcode 141

// Using unordered_set
// Time complexity O(n)
// Space complexity O(n)
bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> nodeHash;
    while(head) {
        if(nodeHash.find(head)!=nodeHash.end()) {
            return true;
        }
        nodeHash.insert(head);
        head = head->next;
    }
    return false;
}


// Time complexity O(n)
// Space complexity O(1)
// Using tortoise hare or slow fast pointer algorithm
// Intuition : Why slow and fast will definitely meet if there is a loop
// Lets say initially the distance between fast to slow is d
// As fast moves 2 node and slow moves 1 node, each step d will reduce by 1
// Eventually d will become 0 and then slow and fast will meet
bool hasCycle(ListNode *head) {
    if(!head || !head->next) {
        return false;
    }
    ListNode *slow = head, *fast = head;
    // Even when number of nodes is one or two
    // This will be handled with below logic
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) {
            return true;
        }
    }
    return false;
}


// In this process we are altering the linked list
// Time complexity O(n)
// Space complexity O(1)
bool hasCycle(ListNode *head) {
    if(!head || !head->next) return false;
    ListNode *dummyNode = new ListNode(0), *prev = nullptr;
    while(head) {
        if(head->next == dummyNode) return true;
        prev = head;
        head = head->next;
        prev->next = dummyNode;
    }
    return false;
}