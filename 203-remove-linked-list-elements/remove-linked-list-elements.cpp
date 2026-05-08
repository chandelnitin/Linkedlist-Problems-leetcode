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
    ListNode* removeElements(ListNode* head, int val) {
         while(head && head->val==val){  // agr mere input 7 7 7 7 hai
            ListNode* deleteNode=head;
            head=head->next;
            delete deleteNode;
         }

         ListNode* prev= NULL;
         ListNode* temp=head;
         while(temp){
            if(temp->val==val){
                prev->next=temp->next;
                ListNode* deleteNode=temp;
                temp=temp->next;  // yhi pr temp ko aage bhadane ka reason hai kuki delete node me 
                delete deleteNode;// temp ka address hai agr dlelete node ko delete krunga to temp
            }                       // temp bhi delete ho jayega . isliye hmme dono condition me 
            else{       // temp ko bhada rahe vrna temp ko only while loop me bhada sakte the /
                prev=temp;  // dono condition me na likh kr 
                temp=temp->next;
            }
           
         }

         return head;
    }
};