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
        ListNode *listA=headA;
        ListNode *listB=headB;
        if(headA==NULL || headB==NULL) return NULL;
        while(listA!=listB) {
            listA=listA==NULL ? headB:listA->next;
            listB=listB==NULL ? headA:listB->next;
        }
        return listA;
    }
};