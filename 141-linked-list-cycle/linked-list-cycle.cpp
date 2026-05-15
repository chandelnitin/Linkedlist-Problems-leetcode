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
//     bool hasCycle(ListNode *head) {
//         ListNode* temp=head;
//         unordered_set<ListNode*>st;
//         while(temp){
//             if(st.find(temp)!=st.end()){
//                 return true;
//             }
//             st.insert(temp);
//             temp=temp->next;
//         }

//         return false;
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
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            // if(fast==slow) return true; // ye condition glat hai yhha kuki suru me to
            fast=fast->next->next;// fast and slow same node pr honge na
            slow=slow->next;
            if(fast==slow) return true;
        }
        
        return false;
    }
};