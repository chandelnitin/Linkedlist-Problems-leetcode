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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* modified=head;
        ListNode* temp=head->next;
        int sum=0;
        while(temp){
            if(temp->val!=0){
                sum+=temp->val;
            }
            else{
                if(temp->next==NULL){
                    modified->val=sum;
                    modified->next=NULL;
                }
                else{
                    modified->val=sum;
                    modified->next=temp;
                    modified=modified->next;
                }
                sum=0;
            }

            temp=temp->next;
        }

        return head;
    }
};