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
    ListNode* deleteDuplicates(ListNode* head) {  
          ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* first = head;
        ListNode* second = head;
        ListNode* prev = dummy;
       
        
        while(first){
           int count=0;
           int curr=first->val;
           while(second && second->val==curr){
               second=second->next;
               count++;
           }
           
           if(count>1){
              prev->next=second;
           }
           else{
              prev=first;
           }
           
           first=second;
        }

        return dummy->next;
    }
};