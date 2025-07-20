/* Problem: Reverse_a_DLL */


class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        if (head == NULL || head->next == NULL) return head;
        DLLNode* prev = NULL;
        DLLNode* current = head;
        while (current != NULL) {
            prev = current->prev;
            current->prev = current->next;
            current->next = prev;
            current = current->prev;
        }
        return prev->prev;
    }
};
/* 
This reversal strategy is single pass
and uses O(1) space, making it efficient for reversing a doubly linked list.

We just interchange the next and prev pointers of each node. 
Use a temporary variable to hold the previous pointer while we swap the pointers.
*/
