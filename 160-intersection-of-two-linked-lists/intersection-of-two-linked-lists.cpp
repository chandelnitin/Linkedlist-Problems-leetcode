// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//            unordered_set<ListNode*>st;
//            ListNode* temp1=headA;
//            while(temp1){
//               st.insert(temp1);   // store every node of tem1
//               temp1=temp1->next;
//            }

//            ListNode* temp2= headB;
//            while(temp2){
//               if(st.find(temp2)!=st.end()){ // agr phale se node exist krti hai to vo hi 
//                   return temp2;// intersection node hai;
//               }
//               temp2=temp2->next;
//            }


//            return NULL;
//     }
// };







/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
          ListNode* a=headA;
          ListNode* b=headB;

          while(a!=b){
             if(a==NULL){
                a=headB;
             }
             else{
                a=a->next;
             }


             if(b==NULL){
                b=headA;
             }
             else{
                b=b->next;
             }
          }

          return a;
    }
};