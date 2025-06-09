/* Problem: Check_if_LL_is_palindrome_or_not */

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
    ListNode* reverse(ListNode* head){
        ListNode *curr=head,*temp,*prev=nullptr; 

        if(head->next==nullptr) return head; 

        while(curr){
            temp=curr->next; 
            curr->next=prev; 
            prev=curr;
            curr=temp;
        }
        return prev; 
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow, *fast; 
        /*
        3 times n/2 -> 
        - once for knowing length & getting mid
        - reversing the rest of linked list post that mid
        - comparing both of them
        */    

        //middle
        slow=head,fast=head; 
        if(head->next==nullptr) return true; 
        //slight difference in the loop codn - to keep the slow at middle in odd cases 
        //& before at the end of 1st half in even cases. 
        while(fast->next && fast->next->next){
            slow=slow->next; 
            fast=fast->next->next;
        }

        ListNode* slow2=reverse(slow->next); 
        //reversal will always be done from slow->next - whether odd or even
        slow=head;
        while(slow2){
            // cout<<slow->val<<" "<<slow2->val<<endl;
            if(slow->val!=slow2->val) return false; 
            slow=slow->next; 
            slow2=slow2->next;  
        }
        return true; 
    }
};