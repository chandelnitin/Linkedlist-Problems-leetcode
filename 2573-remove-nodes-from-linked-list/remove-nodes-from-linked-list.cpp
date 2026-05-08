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
public:  // maine isme stack approch use ki hai jb bhi koi element stack me pde element se bada hota
 // hai to mai stack ke top ko pop krta rahta hu jab tak stack ke top pr greater element nhi milta
 // ab mai mai stack me pade lement se ek list bnata hu lekin prblm ye hai stack pr top element list ka end element hona chaiye first nhi isliye maine reverse linked lis bnai.  dusra trika normal 
 // mai stack ke top ement ko first element bhi bna sakta tha or fir final list ko reverse kr deta .
 // jaise array se list bnao or fir us list ko revrse kr do
    ListNode* removeNodes(ListNode* head) {
        ListNode* mover=head;
        stack<int>st;
        while(mover){
           while(!st.empty() && st.top()<mover->val){
               st.pop();
           }
           st.push(mover->val);
           mover=mover->next;
        }
        ListNode* temp=new ListNode(st.top()) ;
        temp->next=NULL;
        st.pop();
        while(!st.empty()){
            ListNode* newNode =new ListNode(st.top()) ;
            newNode->next=temp;
            temp=newNode;
            st.pop();
        }

        return temp;
    }
};