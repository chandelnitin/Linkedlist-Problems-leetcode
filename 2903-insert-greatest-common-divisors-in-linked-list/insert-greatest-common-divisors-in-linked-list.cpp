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
    int gcd(int a, int b) {
        // Base case
        if (b == 0) {
            return a;
        }

        // Recursive call
        return gcd(b, a % b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp =head;
        ListNode* prev=temp;
        if(head==NULL || head->next==NULL) return head;
        while(temp->next){
            int HCM= gcd(temp->val,temp->next->val);
            ListNode* front= temp->next;
            ListNode* newnode= new ListNode(HCM);
            temp->next=newnode;
            newnode->next=front;
            temp=front;
        }

        return head;
    }
};