/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:// approch hmm current node ke data me agli wali node ka data dalte jayenge or fir last wali node ko delete kr denge . example 1 2 3 4 5 given node 2  . 2 ki jgha 3 fir 3 ki jgha 4 fir 4 ki jgha 5 ab last node 5 hogi use delete kr denge or prev node ko NULL se point kra denge
                    // 1 2 3 4 5
// after operation     1 3 4 5 5   ab last node 5 hai use delete kr denge     
    void deleteNode(ListNode* node) {
        ListNode* given=node;
        ListNode* prev=NULL;
        while(given->next){  // ye isliye check kra kuki hme last node pr rukna hai .kuki agr na 
            given->val=given->next->val; // ruke to hmari given node while loop khatam hone ke 
            prev=given;   // ke bad null ko point kregi . jisse use hmm delete nhi kr payenge
            given=given->next;// or hme last node se pahle wali node NULL se bhi point krana hai
                                //agr hmm given->next check na kre to hmari prev node me last node
        }              // ka adrees hoga jabki hme last node se phali wali node ko numm se ponit 
        prev->next=NULL;   // karana hai
        delete given;
    }
};