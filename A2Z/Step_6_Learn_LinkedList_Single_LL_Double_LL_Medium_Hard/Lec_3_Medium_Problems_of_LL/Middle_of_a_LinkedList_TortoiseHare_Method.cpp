/* Problem: Middle_of_a_LinkedList_TortoiseHare_Method */


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head; 
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next; 
            fast=fast->next->next;
        }
        return slow;
    }
};