/* Problem: Segrregate_odd_and_even_nodes_in_LL */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *evenHead, *odd, *even, *temp; 
        if(head==nullptr || head->next==nullptr) return head; 
        evenHead=head->next;
        odd=head; 
        even=evenHead; 
        while(even!=NULL && even->next!=NULL){
            odd->next=even->next;
            even->next=odd->next->next; 
            odd=odd->next;
            even=even->next; 
        }
        odd->next=evenHead; 

        return head; 
    }
};