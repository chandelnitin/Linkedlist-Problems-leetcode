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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* odd=head;
        ListNode* even =head->next;
        while( even && even->next){   // jb mera odd 3 and even 4 pr hoga to even ka next
            swap(odd->val,even->val);// null hoga or mai while condition me check kr raha
            odd=even->next;// ki even ka next true hai ya nhi . to 3 and 4 swap nhi honge
            even=odd->next;
        }
        
       if(odd->next) swap(odd->val ,even->val); // ye condition odd length ki list ke liye lgai vrna only swap bhi kr sakta tha . kuki agr list odd hai to mera odd hai to even mera null hoga or mai even->val check krra hu to error dega 

        return head;
    }
};