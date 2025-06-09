/* Problem: Rotate_a_LL */

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || !head || !head->next) return head; 
        ListNode* tail=head, *last=head, *newHead; 
        int len=1;
        while(tail->next!=nullptr) tail=tail->next, len++;

        k=k%len; 
        if(k==0) return head; 
        int pt=len-k-1;
        while(pt--) last=last->next; 

        newHead=last->next; 
        last->next=nullptr;
        tail->next=head; 

        return newHead; 
    }
};