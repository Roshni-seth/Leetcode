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
    ListNode* findMid(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* mergeList(ListNode* lefthead, ListNode* righthead) {
        ListNode* left=lefthead;
        ListNode* right=righthead;
        ListNode* dummynode=new ListNode(-1);
        ListNode* temp=dummynode;
        while(left!=NULL && right!=NULL) {
            if(left->val<=right->val) {
                temp->next=left;
                left=left->next;
            }
            else {
                temp->next=right;
                right=right->next;
            }
            temp=temp->next;
        }
        if(left!=NULL) {
            temp->next=left;
        }
        else  temp->next=right;
        return dummynode->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *middle=findMid(head);
        ListNode *lefthead=head;
        ListNode *righthead=middle->next;
        middle->next=NULL;
        lefthead=sortList(lefthead);
        righthead=sortList(righthead);
        return mergeList(lefthead,righthead);
    }
};