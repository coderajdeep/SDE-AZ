// Remove duplicates from sorted List II -- leetcode 82
// Time complexity O(nlogn)
// Space complexity O(n)
ListNode* deleteDuplicates(ListNode* head) {
    if(!head || !head->next) return head;
    map<int, int> map_;
    ListNode *curr = head;
    while(curr) {
        map_[curr->val]++;
        curr = curr->next;
    }
    ListNode *dummy = new ListNode(0);
    ListNode *ptr = dummy;
    for(pair<int, int> p : map_) {
        if(p.second==1) {
            dummy->next = new ListNode(p.first);
            dummy = dummy->next;
        }
    }
    return ptr->next;
}