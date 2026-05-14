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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int>has(nums.begin(),nums.end());
        ListNode* temp=head;
        int ans=0;
        while(temp){
            if(has.find(temp->val)!=has.end()){
                while(temp && has.find(temp->val)!=has.end()){
                    temp=temp->next;
                }
                ans++;
            }
            else{
                temp=temp->next;
            }  
        }

        return ans;
    }
};