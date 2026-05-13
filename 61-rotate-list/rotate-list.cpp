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
        ListNode* slow=head; ListNode* fast=head;
        ListNode* temp=head;
        if(k==0 || head==NULL || head->next==NULL) return head;
        int listleng=0;
        while(temp){
            listleng++;
            temp=temp->next;
        }
        if(k%listleng==0) return head;
        if(k>listleng)k=k%listleng;

        temp =head;
        for(int i=0;i<k;i++){ // fast ko k times aage bhada do;
            fast=fast->next;
        }
        
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=head;
        ListNode* newhead=slow->next;
        slow->next=NULL;

        return newhead;
    }
};