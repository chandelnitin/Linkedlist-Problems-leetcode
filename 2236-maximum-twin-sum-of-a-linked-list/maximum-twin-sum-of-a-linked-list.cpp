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
// public: // twin frist and last honge list ke fir second or list ke second last isliye deque me strore kr kiye sare element kuki deque me front or back dono ka access hota hai
//     int pairSum(ListNode* head) {
//         deque<int>dq;
//         ListNode* temp=head;
//         while(temp){
//             dq.push_back(temp->val);
//             temp=temp->next;
//         }
//         int sum=0;
//         int Max=INT_MIN;
//         while(!dq.empty()){
//            sum=dq.front()+dq.back();
//            dq.pop_front();
//            dq.pop_back();
//            Max=max(sum,Max);
//         }

//         return Max;
//     }
// };



















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
//     int pairSum(ListNode* head) {
//         stack<int>st;
//         ListNode* temp=head;
//         while(temp){
//             st.push(temp->val);
//             temp=temp->next;
//         }

//         temp=head;
//         int sum=0; int n=st.size();
//         int maxSum=INT_MIN;
//         for(int i=0;i<n/2;i++){
//             sum=temp->val+st.top();
//             st.pop();
//             maxSum=max(maxSum,sum);
//             temp=temp->next;
//         }
        

//         return maxSum;
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
public:  // half rerve method 
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
       
        ListNode* prev=NULL;
        ListNode* curr=slow;
        while(curr){
            ListNode* front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }

        int sum=0;int maxSum=INT_MIN;
        ListNode*first=head;
        ListNode* second=prev;
        while(second){
            sum=first->val+second->val;
            first=first->next;
            second=second->next;
            maxSum=max(maxSum,sum);
        }

        return maxSum;
    }
};

