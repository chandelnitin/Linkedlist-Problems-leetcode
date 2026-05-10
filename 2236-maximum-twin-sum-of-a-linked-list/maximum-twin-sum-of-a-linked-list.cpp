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
public: // twin frist and last honge list ke fir second or list ke second last isliye deque me strore kr kiye sare element kuki deque me front or back dono ka access hota hai
    int pairSum(ListNode* head) {
        deque<int>dq;
        ListNode* temp=head;
        while(temp){
            dq.push_back(temp->val);
            temp=temp->next;
        }
        int sum=0;
        int Max=INT_MIN;
        while(!dq.empty()){
           sum=dq.front()+dq.back();
           dq.pop_front();
           dq.pop_back();
           Max=max(sum,Max);
        }

        return Max;
    }
};