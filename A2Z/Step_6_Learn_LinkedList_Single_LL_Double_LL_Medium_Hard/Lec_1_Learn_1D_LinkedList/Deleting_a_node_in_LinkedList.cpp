/* Problem: Deleting_a_node_in_LinkedList */

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp=node->next;
        node->val=temp->val;
        node->next=temp->next;
        delete temp;
    }
};