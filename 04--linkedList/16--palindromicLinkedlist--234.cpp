// Check if a linkedlist is palindrom or not -- leetcode 234

// Recursive approch
// very tricky
// Time complexity O(n)
// Recursive Space complexity O(n)
class Solution {
public:
    ListNode* left;
    bool isPalindromUtils(ListNode* right) {
        if(!right) return true;
        bool subListCheck = isPalindromUtils(right->next);
        if(!subListCheck) return false;
        bool valueCheck = (left->val == right->val);
        left = left->next;
        return valueCheck;
    }
    bool isPalindrome(ListNode* head) {
        left = head;
        return isPalindromUtils(head);
    }
};

// Same as previous
class Solution {
public:
    bool isPalindromUtils(ListNode** left, ListNode* right) {
        if(!right) return true;
        bool subListCheck = isPalindromUtils(left, right->next);
        if(!subListCheck) return false;
        bool valueCheck = ((*left)->val == right->val);
        (*left) = (*left)->next;
        return valueCheck;
    }
    bool isPalindrome(ListNode* head) {
        return isPalindromUtils(&head, head);
    }
};

// Fast and slow pointer approach
// Time complexity O(n)
// Space complexity O(1)
ListNode* reverseLinkedList(ListNode* root) {
    if(!root || !root->next) {
        return root;
    }
    ListNode *curr = root, *prev = nullptr, *nxt = nullptr;
    while(curr) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}
bool isPalindrome(ListNode* head) {
    if(!head || !head->next) {
        return true;
    }
    ListNode *slow = head, *fast = head, *prev = head;
    while(fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = nullptr;
    if(fast) {
        slow = slow->next;
    }
    slow = reverseLinkedList(slow);
    while(head && slow) {
        if(head->val!=slow->val) {
            return false;
        }
        head = head->next;
        slow = slow->next;
    }
    return true;
}

// Time complexity O(n)
// Space complexity O(n)
// Using stack
bool isPalindrome(ListNode* head) {
        
    if(!head or !head->next) {
        return true;
    }
    
    stack<int>st;
    
    ListNode *curr = head;
    
    while(curr) {
        st.push(curr->val);
        curr = curr->next;
    }
    
    curr = head;
    
    while(curr) {
        if(curr->val != st.top()) {
            return false;
        }
        st.pop();
        curr = curr->next;
    }

    return true;
}