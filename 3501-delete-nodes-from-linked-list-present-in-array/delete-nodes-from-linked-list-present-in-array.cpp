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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st;
        for(auto & num:nums){
            st.insert(num);
        }

        while(head && st.find(head->val)!=st.end()){  // sari first node delete krna. kr isliye rahe
 // agr pahle wala node  nums me ho to hme se delete krna pdega  .or agle wale while loop me       prev->next kr rahe hai lekin hmara prev null ko point kr raha hoga to vo error dega . isse ensure ho jayega ki phale wala node ki value nums me nhi hogi.kuki is while loop me starting sari node delete ho rahi jo nums me hai
            head=head->next;
           
        }

        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp){
            if(st.find(temp->val)!=st.end()){
                prev->next=temp->next;
                temp=temp->next;// yhi pr temp ko aage bhadane ka reason hai kuki delete node me 
                // temp ka address hai agr dlelete node ko delete krunga to temp
                                // temp bhi delete ho jayega . isliye hmme dono condition me 
            }            // temp ko bhada rahe vrna temp ko only while loop me bhada sakte the 
            else{        // dono condition me na likh kr 
                prev=temp;
                temp=temp->next;
            }
        }
        
        return head;
    }
};