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
// class Solution { // O(n) SC o
// public:
//     ListNode* partition(ListNode* head, int x) {
//         vector<int>v1;
//         vector<int>v2;
//         ListNode* temp=head;
//         if(head==NULL || head->next==NULL) return head;
//         while(temp){
//             if(temp->val<x){
//                 v1.push_back(temp->val);
//             }
//           else{
//                 v2.push_back(temp->val);
//             }

//             temp=temp->next;
//         }

//         temp=head;
//         int i=0; int j=0;
//         int v1size= v1.size();int v2size=v2.size();
//         while(temp){
//             if(i<v1size){
//                 temp->val=v1[i++];
//             }
//             else{
//                 temp->val=v2[j++];
//             }

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
class Solution { // O(n) 
public:
    ListNode* partition(ListNode* head, int x) {
       ListNode* smallDummy= new ListNode(0);
       ListNode* largeDummy= new ListNode(0);
       
       ListNode* small=smallDummy;
       ListNode* large=largeDummy;
       ListNode* temp=head;
       if(head==NULL || head->next==NULL) return head;
       while(temp){
          if(temp->val<x){
             small->next=temp;
             temp=temp->next;
             small=small->next;
            //  smallDummy->next=NULL;
          }
          else{
             large->next=temp;
             temp=temp->next;
             large=large->next;
            //  largeDummy->next=NULL;
          }
       }


        small->next=largeDummy->next;
        large->next=NULL;
          return smallDummy->next;

    }
};