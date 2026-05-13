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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp=list1;
        ListNode* prev=NULL;
         ListNode* list2temp=list2;
        int count=0;
        while(temp){
            if(count==a){
              prev->next=list2;
              while(list2temp->next){
                  list2temp=list2temp->next;
              }
            }

            if(count==b){
                list2temp->next=temp->next;
                temp->next=NULL;
                break;
            }
            prev=temp;
            temp=temp->next;
            count++;
        }

        return list1;
    }
};