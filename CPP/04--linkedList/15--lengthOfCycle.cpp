// Length of cycle in linkedlist -- coding ninjas


// Time complexity O(n)
// Space complexity O(n)
int lengthOfLoop(Node *head) {
    if(!head || !head->next) return 0;
    unordered_map<Node*, int> umap;
    int time = 0;
    while(head) {
        auto itr = umap.find(head);
        if(itr != umap.end()) {
            return (time - itr->second);
        }
        umap[head] = time++;
        head = head->next;
    }
    return 0;
}

// Time complexity O(n)
// Space complexity O(1)
int lengthOfLoop(Node *head) {
    if(!head || !head->next) return 0;
    Node *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            int count = 1;
            while(fast->next != slow) {
                fast = fast->next;
                ++count;
            }
            return count;
        }
    }
    return 0;
}

// Using Extra space
// Time complexity O(n)
// Space complexity O(n)
int lengthOfLoop(Node *head) {
    if(!head || !head->next) {
        return 0;
    }
    unordered_set<Node*> s;
    bool isLoopExist = false;
    Node *root = head;
    while(root) {
        if(s.find(root)!=s.end()) {
            isLoopExist = true;
            break;
        }
        s.insert(root);
        root = root->next;
    }
    if(!isLoopExist) {
        return 0;
    }
    head = root;
    int len = 1;
    while(root->next!=head) {
        root = root->next;
        len += 1;
    }
    return len;
}

// Slow and fast pointer approach
int getLoopLength(Node *root) {
    Node *curr = root->next;
    int len = 1;
    while(curr!=root) {
        curr = curr->next;
        ++len;
    }
    return len;
}

int lengthOfLoop(Node *head) {
    if(!head || !head->next) {
        return 0;
    }
    Node *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) {
            return getLoopLength(slow);
        }
    }
    return 0;
}


// Using constant space
// Time complexity O(n)
// Space complexity O(1)
int lengthOfLoop(Node *head) {
    if(!head || !head->next) {
        return 0;
    }
    Node *slow = head, *fast = head;
    bool isLoopExist = false;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) {
            isLoopExist = true;
            break;
        }
    }
    if(!isLoopExist) {
        return 0;
    }
    int len = 1;
    while(slow->next!=fast) {
        ++len;
        slow = slow->next;
    }
    return len;
}