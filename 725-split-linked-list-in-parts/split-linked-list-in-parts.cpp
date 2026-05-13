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
    vector<ListNode*> splitListToParts(ListNode* head, int k) { 
        vector<ListNode*>ans(k,NULL);
         ListNode* temp=head;
         int listlen=0;
         while(temp){
            listlen++;
            temp=temp->next;
         }
         temp=head;
         int size= listlen/k;
         int extra=listlen%k;;
         for(int i=0;i<k && temp;i++){
            ans[i]=temp;
            int listsize= size+ ((extra>0)?1:0);
            extra--;
            for(int j=1;j<listsize &&temp;j++){ //agr mera sie 3 hai to loop 2 bar chlega
                temp=temp->next;         // kuki temp ek extra chal raha hai
            }
            ListNode* front=temp->next; //man lo lissize 1 hai to temp already 1 element 
            temp->next=NULL;// pr hai  bs hme temp ko null se point krna hai . to iska
            temp=front;// matlab 1 size ke liye j wala loop chalna hi nhi chahiye.mtlab
         }           // loop hmesa ek km chalega listzuse se
        return ans;
    }
};