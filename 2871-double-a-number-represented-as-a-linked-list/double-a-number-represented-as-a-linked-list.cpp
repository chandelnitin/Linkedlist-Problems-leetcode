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
    ListNode* revrseList(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr){
            ListNode* front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }

        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp1 =  revrseList(head);
        ListNode* revhead=temp1;
        int carry=0;
        ListNode* prev=NULL;
        while(temp1){
            int num= temp1->val*2+carry;
            temp1->val= num%10;
            carry=num/10;
            prev=temp1;
            temp1=temp1->next;
        }

        if(carry){
            ListNode* newnode=new ListNode(carry);
            prev->next=newnode;
        }
      
       return revrseList(revhead);
    }
};