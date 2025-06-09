/* Problem: Find_the_intersection_point_of_Y_LL */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pt1=headA, *pt2=headB; 
        while(pt1!=pt2){
            pt1= (pt1==NULL)? pt1=headB:pt1->next; 
            pt2= (pt2==NULL)? pt2=headA:pt2->next; 
        }
        /*
        Both get to travel: m+n length. 
        If they have intersection: the change of head takes off the difference and they meet at the intersection point 
        or Else: they complete the m+n length journey & both end up at null; 
        */
        return pt1;
    }
};