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
// public:
//     void reorderList(ListNode* head) {
//         deque<int>st;
//         ListNode* temp=head;
//         while(temp){
//             st.push_back(temp->val);
//             temp=temp->next;
//         }

//         temp=head;
//         int count=1;
//         while(temp){
//             if(count%2==0){
//                 temp->val=st.back();
//                 st.pop_back();
//             }
//             else{
                
//                 temp->val=st.front();
//                 st.pop_front();
//             }
//             temp=temp->next;
//             count++;
//         }  

       
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
    void reorderList(ListNode* head) {
        stack<ListNode*>st; // hmm stack me node store kr rahe hai
        ListNode* temp=head;
         if(!head || !head->next) return;
        while(temp){
            st.push(temp);
            temp=temp->next;
        }

        temp=head;
       int n=st.size();
       for(int i=0;i<n/2;i++){
          ListNode* curr=temp;  // maine curr node ko store kraya kuki curr node ke next
          temp=temp->next;  // me mujhe last node ka address dalna hai jo stack ke top pr
          curr->next=st.top(); // hai lekin agr m curr na likhta to temp ke next me stack
          st.pop();  // ka top aa jata or jb mai temp ko agge bhadaat to vo stack ke jo
          curr->next->next=temp;// top pr node hai us pr chal jata yani list ke end node
       }      // pr jabki mujhe temp ko list ke agle element pr le jana hai
          // ab meri list 3 4 bachi ab isko connect krana hai jo list maine bnai hai yani
       temp->next=NULL;  // 1 2 se . lekin mera curr 1 pr hai isliye 3 4 list ko 2 ke next me dalna hai isliye maine curr->next->next kiya hai
       
    }
};