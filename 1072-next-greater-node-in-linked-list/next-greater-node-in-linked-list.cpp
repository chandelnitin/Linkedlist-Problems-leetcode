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
    vector<int> nextLargerNodes(ListNode* head) {
         vector<int>nums; // list value copy in nums
         ListNode* temp=head;
         while(temp){
            nums.push_back(temp->val);
            temp=temp->next;
         }
         int n=nums.size();
         vector<int> ans(n,0);
         stack<int>st; // indecies
         
         for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                  ans[st.top()]=nums[i];
                  st.pop();
            }

            st.push(i);
         }

         return ans;
    }
};