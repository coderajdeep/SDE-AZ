// Check if a linkedlist is circular or not -- geeks

bool isCircular(Node *head)
{
   if(!head || !head->next) return false;
   Node *curr = head;
   while(curr && curr->next!=head) {
       curr = curr->next;
   }
   return (curr != nullptr);
}