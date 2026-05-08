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
// class Solution {  // o(n) sc O(n)
// public:  // maine isme stack approch use ki hai jb bhi koi element stack me pde element se bada hota
//  // hai to mai stack ke top ko pop krta rahta hu jab tak stack ke top pr greater element nhi milta
//  // ab mai mai stack me pade lement se ek list bnata hu lekin prblm ye hai stack pr top element list ka end element hona chaiye first nhi isliye maine reverse linked lis bnai.  dusra trika normal 
//  // mai stack ke top ement ko first element bhi bna sakta tha or fir final list ko reverse kr deta .
//  // jaise array se list bnao or fir us list ko revrse kr do
//     ListNode* removeNodes(ListNode* head) {
//         ListNode* mover=head;
//         stack<int>st;
//         while(mover){
//            while(!st.empty() && st.top()<mover->val){
//                st.pop();
//            }
//            st.push(mover->val);
//            mover=mover->next;
//         }
//         ListNode* temp=new ListNode(st.top()) ;
//         temp->next=NULL;
//         st.pop();
//         while(!st.empty()){
//             ListNode* newNode =new ListNode(st.top()) ;
//             newNode->next=temp;
//             temp=newNode;
//             st.pop();
//         }

//         return temp;
//     }
// };







class Solution {  // o(n) sc O(n)
public:   // approch hmm list me last traverse krnege jiske liye hme list ko revrse krna pdega o
// last se traverse krte time hmm max elemnt strore krte chalnge agr aage aane wale element max se chota hai iska matlab curr element ke right me ysse bada ekement hai jaise  13 3 8 list me 8 maximum hai suru me.(last element hmesa aayega ouptput me kuki sabse last elemnt ke right me koi greater element nhi hai). ab hmm 3 pr aayenge or chek krenge ki 3 max se bada hai kya nhi hai to 3 output me nhi aayega kuki max element hmm 3 ke right se hi le raha hai . or agr hme max elelt se bada element milta hai to max ko update krenge or reverse list create krenge .
    ListNode* removeNodes(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr){  // linked list reverse ho gyi ab new head prev hoga
             ListNode* front = curr->next;
             curr->next=prev;
             prev=curr;
             curr=front;
        }
        // prev head hai ab list ka 
        int maxelment=prev->val;
        ListNode* temp= new ListNode(prev->val);
        prev=prev->next;
        temp->next=NULL;
        while(prev){   
            if(prev->val>=maxelment){
               ListNode* newNode= new ListNode(prev->val);
               newNode->next=temp;
               temp=newNode;
                maxelment=prev->val;
            }

            prev=prev->next;
        }

        return temp;
    }
};