/* Problem: Reverse_a_LinkedList_Iterative */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //O(1) approach iteration
        ListNode *temp=head,*prev=nullptr,*nxt;
        while(temp!=nullptr){
            nxt=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nxt;
        }
        return prev;
    }
};