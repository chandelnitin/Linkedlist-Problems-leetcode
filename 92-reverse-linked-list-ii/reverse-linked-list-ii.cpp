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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(0);// agr hmm ye na bnaye or left hme 1 diya hua ho
        dummy->next=head;// prev null pr hoga or jb hmm reconnect krenge to NULL ke next
        ListNode* prev=dummy;// me revrse list ka head kaise dalnege 


        // move prev before the left kuki prev ke next me revrse list ka head aayega
        for(int i=1;i<left;i++){
            prev=prev->next;
        }
       // revrse left to right  
        ListNode* prevnode=NULL;
        ListNode* curr=prev->next;
        ListNode* front=NULL;
        for(int i=1;i<=right-left+1;i++){
            front=curr->next;
            curr->next=prevnode;
            prevnode=curr;
            curr=front;
        }

        // prevnode=4-3-2-NULL    curr->5 
         
         // reconnect
         // prev hav 1 or prev ka next 2
         prev->next->next=curr;  // yani 2 ke next me 5 aagya
         prev->next=prevnode ;// yani 1 ke next me revrse node ka head yani 4 aagya

         return dummy->next;
     
    }
};