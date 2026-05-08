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
      ListNode* temp=head;
      if(head == NULL || head->next == NULL){
          return NULL;
      }
       
      int len=0;
      while(temp){
          len++;
          temp=temp->next;
      }
      temp=head;
      int kth=(len/2)+1;   // delete kth node
      int count=0;
      ListNode* prev=NULL;
      while(temp){
          count++;
          if(count==kth){
              prev->next=prev->next->next;
              break;
          }
          prev=temp;
          temp=temp->next;
      }
       
      return head;
    }
};