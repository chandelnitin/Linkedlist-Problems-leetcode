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
    ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr){
            ListNode* front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }

        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseList(l1);
        l2=reverseList(l2);
        int carry=0;
        ListNode* addList=new ListNode(0);
        ListNode* addListhead=addList;
        while(l1 || l2){
            int num1=(l1!=NULL)?l1->val:0;
            int num2 = (l2!=NULL)?l2->val:0;
            int sum=num1+num2+carry;
            ListNode* newlist=new ListNode(sum%10);
            addList->next=newlist;
            addList=addList->next;
            carry=sum/10;
           if(l1) l1=l1->next;
           if(l2) l2=l2->next;
        }

        while(carry){
            ListNode* newList= new ListNode(carry%10);
            addList->next=newList;
            addList=addList->next;
            carry=carry/10;
        }
        
        return reverseList(addListhead->next);
    }
};