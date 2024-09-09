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
    bool hasCycle(ListNode *head) {
        ListNode *temp=head;
        unordered_map<ListNode*,int> unmp;
        while(temp!=NULL) {
            if(unmp.find(temp)!=unmp.end())
                return true;
            unmp[temp]=1;
            temp=temp->next;
        }
        return false;
    }
};