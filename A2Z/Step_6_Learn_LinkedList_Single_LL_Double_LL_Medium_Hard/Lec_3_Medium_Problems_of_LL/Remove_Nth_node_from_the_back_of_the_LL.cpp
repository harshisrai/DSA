/* Problem: Remove_Nth_node_from_the_back_of_the_LL */

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow, *fast,*temp; 
        fast=head;

        if(fast->next==nullptr) return nullptr; 

        for(int i=0;i<n;i++) fast=fast->next; 

        if(fast==nullptr){
            // n is the length then, head is to be deleted
            ListNode* newHead=head->next; 
            delete head; 
            return newHead;  
        }
        slow=head; 
        while(fast->next!=nullptr){
            fast=fast->next;
            slow=slow->next; 
        }  
        ListNode* nodeToDelete=slow->next;  
        slow->next=slow->next->next; 
        delete nodeToDelete; 
        return head;  
    }
};

/*
Ultimate concept is: 
- Move n steps ahead
- if at the NULL, head is to be deleted
- else keep moving forward the fast and slow(form head) till fast reaches end node
- slow will be at prev to the nth node, use it to delete