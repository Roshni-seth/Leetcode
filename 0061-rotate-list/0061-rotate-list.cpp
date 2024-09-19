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
    ListNode* rotateRight(ListNode* head, int k) {
        int len=0;
        if(head==NULL || head->next==NULL) return head;
        ListNode *temp=head,*pnt=NULL;
        while(temp!=NULL) {
            len++;
            pnt=temp;
            temp=temp->next;
        }
        pnt->next=head;
        k=len-k%len;
        temp=head;
        while(k>1) {
            temp=temp->next;
            k--;
        }
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};