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
        deque<int>st;
        ListNode* temp=head;
        while(temp){
            st.push_back(temp->val);
            temp=temp->next;
        }

        temp=head;
        int count=1;
        while(temp){
            if(count%2==0){
                temp->val=st.back();
                st.pop_back();
            }
            else{
                
                temp->val=st.front();
                st.pop_front();
            }
            temp=temp->next;
            count++;
        }  

       
    }
};