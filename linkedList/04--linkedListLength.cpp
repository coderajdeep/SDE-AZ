// Length of singly linked list


/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

// Time complexity O(n)
// Space complexity O(1)
int length(Node *head) {
	int len = 0;
    while(head) {
        head = head->next;
        ++len;
    }
    return len;
}


// Recursive
// Time complexity O(n)
// Space complexity O(1) + recursive stack space O(n)
int length(Node *head) {
	return !head ? 0 : 1 + length(head->next);
}