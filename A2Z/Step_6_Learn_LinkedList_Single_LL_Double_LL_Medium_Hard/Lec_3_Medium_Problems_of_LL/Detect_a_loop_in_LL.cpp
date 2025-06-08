/* Problem: Detect_a_loop_in_LL */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head, *fast=head; 
        while(fast!=NULL && fast->next!=NULL){
            // cout<<slow->val<<" "<<fast->val<<endl; 
            slow=slow->next; 
            fast=fast->next->next; 
            if(slow==fast) return true;  
             /*this comparision should be done at end because 
            when the loop started, they were equal and we want to see when the equality occured 
            post that point*/
        }
        return false; 
    }
};