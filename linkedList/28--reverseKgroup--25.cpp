// Reverse a linkedlist in group of size k -- leetcode 25
// recursive method
// Time complexity O(n)
// Recursion stack space complexity O(n/k)

int getLength(ListNode *head) {
    ListNode *fast = head, *slow = head;
    int cnt = 0;
    while(fast && fast->next) {
        slow = slow;
        fast = fast->next->next;
        ++cnt;
    }
    int len = 2 * cnt;
    if(!fast) return len;
    return (len + 1);
}
ListNode* reverseList(ListNode* head, int k, int length) {
    if(!head || !head->next) return head;
    if(k > length) return head;
    ListNode *curr = head, *prev = nullptr, *nxt = nullptr;
    int count = 0;
    while(curr && count < k) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        ++count;
    }
    if(nxt) {
        head->next = reverseList(nxt, k, length - k);
    }
    return prev;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    if(!head || !head->next || k==1) return head;
    int length = getLength(head);
    return reverseList(head, k, length);
}


// Iterative method
// Time complexity O(n)
// Space complexity O(1)
int getLength(ListNode *head) {
    ListNode *slow = head, *fast = head;
    int length = 0;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        ++length;
    }
    if(!fast) return (2*length);
    return (2*length + 1);
}
ListNode* reverseKGroup(ListNode* head, int k) {
    if(!head || !head->next || k==1) return head;
    int length = getLength(head);
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prev = dummy, *curr = nullptr, *nxt = nullptr;
    while(k <= length) {
        curr = prev->next;
        nxt = curr->next;
        // we need to do this process k-1 times
        for(int i=1; i<k; ++i) {
            curr->next = nxt->next;
            // we can think, prev->next and curr is same
            // but it's not inside the loop
            // every time prev->next is updating but curr is not
            // nxt->next = curr;
            // if we use this above line then only (n/k < 2) case this will work
            // otherwise this will not work
            nxt->next = prev->next;
            prev->next = nxt;
            nxt = curr->next;
        }
        // [1 2 3 4 5 6 7] k = 4
        // with dummy [0 1 2 3 4 5 6 7] 
        // prev 0
        // curr 1
        // nxt 2
        // After k-1 intration
        // [0 4 3 2 1 5 6 7]
        // prev 0
        // curr 1
        // nxt 5
        prev = curr;
        length = length - k;
    }
    return dummy->next;
}

// Geeks reversal
// Here if the length < k still we need to reverse
// Iterative method
// Time complexity O(n)
// Space complexity O(1)
struct node *reverseIt (struct node *head, int k) { 
    if(!head || !head->next || k==1) return head;
    node *dummy = new node(0);
    dummy->next = head;
    node *prev = dummy, *curr=nullptr, *nxt=nullptr;
    
    while(true) {
        curr = prev->next;
        nxt = curr->next;
        for(int i=1; nxt && i<k; ++i) {
            curr->next = nxt->next;
            nxt->next = prev->next;
            prev->next = nxt;
            nxt = curr->next;
        }
        if(!nxt) break;
        prev = curr;
    }
    return dummy->next;
}

// Recursive method
// Time complexity O(n)
// Recursion stack space complexity O(n/k)
struct node *reverseIt (struct node *head, int k) { 
    if(!head || !head->next || k==1) return head;
    node *curr = head, *prev = nullptr, *nxt = nullptr;
    int count = 0;
    while(curr && count < k) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        ++count;
    }
    if(nxt) {
        head->next = reverseIt(nxt, k);
    }
    return prev;
}