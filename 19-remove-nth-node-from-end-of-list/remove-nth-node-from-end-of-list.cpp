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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len=0;
        
        while(temp){
            len++;
            temp=temp->next;
        }
        if(n==len){   // delete first node
            head=head->next;
            return head;
        }

        
        int kth=len-n; // delete node from the starting +1
        temp=head;
        ListNode* prev=NULL;
        int count=0;
        while(temp){
            if(count==kth){
                prev->next=temp->next;
                delete temp;
                break;
            }

            count++;
            prev=temp;
            temp=temp->next;
        }
        
        return head;
    }
};