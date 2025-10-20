// // Function to reverse a singly linked list
// struct ListNode* reverseList(struct ListNode* head) {
//     struct ListNode* prev = NULL;
//     struct ListNode* current = head;
//     struct ListNode* next = NULL;

//     while (current != NULL) {
//         next = current->next; // Store the next node
//         current->next = prev; // Reverse the current node's next pointer
//         prev = current;       // Move prev and current one step forward
//         current = next;
//     }

//     return prev; // prev will be the new head of the reversed list
// }