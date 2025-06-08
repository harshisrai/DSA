/* Problem: Reverse_a_LL_Recursive */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //O(1) approach iteration
        if(head==nullptr) return head;
        return rev(nullptr,head);
    }
    ListNode* rev(ListNode *prev,ListNode *curr){
        ListNode* head;
        if(curr->next==nullptr){
            curr->next=prev;
            return curr;
        }
        else {
            head=rev(curr,curr->next);
            curr->next=prev;
        }
        return head;
    }
};