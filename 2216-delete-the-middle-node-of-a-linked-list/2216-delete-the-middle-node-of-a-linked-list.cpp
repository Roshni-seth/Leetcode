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
        ListNode *fast=head;
        ListNode *slow=head;
        ListNode *temp=NULL;
        if(head==NULL || head->next==NULL) return NULL;
        while(fast->next!=NULL && fast->next->next!=NULL) {
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast->next==NULL) {
            temp->next=slow->next;
            delete slow;
            return head;
        }
        else if(fast->next->next==NULL) {
            ListNode *delnode=slow->next;
            slow->next=slow->next->next;
            delete delnode;
            return head;
        }
        return head;
    }
};