// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public: o(N) SC O(n)
//     ListNode* oddEvenList(ListNode* head) {
//         vector<int>nums;
//         ListNode* temp=head;
//         while(temp){
//             nums.push_back(temp->val);
//             temp=temp->next;
//         }
//         temp=head;
//         for(int i=0;i<nums.size();i=i+2){
//             temp->val=nums[i];
//             temp=temp->next;
//         }

//         for(int i=1;i<nums.size();i=i+2){
//             temp->val=nums[i];
//             temp=temp->next;
//         }

//         return head;
//     }
// };


















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
    ListNode* oddEvenList(ListNode* head) {
        if(head ==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        ListNode* odd=head;
        ListNode* oddprev=temp;
        temp=temp->next;
        ListNode* even=temp;
        ListNode* evenprev=temp;
        temp=temp->next;
        int count=3;
        while(temp){
           if(count%2==0){
              evenprev->next=temp;
              evenprev=temp;
           } 
           else{
              oddprev->next=temp;
              oddprev=temp;
           }

           temp=temp->next;
           count++;
        }
        evenprev->next=NULL;
        oddprev->next=even;
      
        return odd;
    }
};
