/* Problem: Delete_the_middle_node_of_LL */

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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *slow=head, *fast=head, *temp;
        if(fast->next==nullptr) return nullptr;

        //the loop should stop when i either reach the null or the end
        // thus continue if I am neither at null and neither at the end
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next; 
            temp=slow;
            slow=slow->next; 
        }
        temp->next=slow->next; 
        delete slow; 
        return head; 
    }
};