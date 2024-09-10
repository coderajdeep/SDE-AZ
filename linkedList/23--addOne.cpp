// Will do recursive and stack solution later

// Time complexity O(n)
// Recursive Space complexity O(n)
void addOneUtils(Node *&left,  Node *right, int &carry) {
    if(!right) return;
    addOneUtils(left, right->next, carry);
    int num = right->data + carry;
    right->data = (num % 10);
    carry = num / 10;
    left = left->next;
}
Node *addOne(Node *head)
{
    int carry = 1;
    Node *left = head, *right = head;
    addOneUtils(left, right, carry);
    if(carry) {
        Node *temp = new Node(carry);
        temp->next = head;
        head = temp;
    }
    return head;
}

// Time complexity O(n)
// Space complexity O(1)
Node *reverseLinkedlist(Node *head) {
    if(!head || !head->next) {
        return head;
    }
    Node *curr = head, *prev = nullptr, *nxt = nullptr;
    while(curr) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}
Node *addOne(Node *head)
{
    Node *revHead = reverseLinkedlist(head), *prev = nullptr;
    Node *newHead = revHead;
    int carry = 1;
    while(revHead) {
        prev = revHead;
        int num = revHead->data + carry;
        revHead->data =  num % 10;
        carry = num / 10;
        revHead = revHead->next;
    }
    if(carry) prev->next = new Node(carry);
    return reverseLinkedlist(newHead);
}