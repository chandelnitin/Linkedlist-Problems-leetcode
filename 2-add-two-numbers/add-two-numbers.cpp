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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int carry=0;
         int num1=(temp1!=NULL)?temp1->val:0;
         int num2=(temp2!=NULL)?temp2->val:0;
         int sum=num1+num2;
         ListNode* ans=new ListNode(sum%10);
         ListNode* head=ans;
         temp1=temp1->next;
         temp2=temp2->next;
         carry=sum/10;
        while(temp1 || temp2){
            int num1=(temp1!=NULL)?temp1->val:0;
            int num2=(temp2!=NULL)?temp2->val:0;
            sum=num1+num2+carry;
            ListNode* newNode=new ListNode(sum%10);
            ans->next=newNode;
            ans=ans->next;
            carry=sum/10;
            if(temp1) temp1=temp1->next;
            if(temp2) temp2=temp2->next;
            
        }

        while(carry){
            int digit=carry%10;
            ListNode* newNode= new ListNode(digit);
            ans->next=newNode;
            carry=carry/10;

        }

        return head;
    }
};