/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Deletes middle of linked list and returns head of the modified list
class Solution {
  public:
    Node* deleteMid(Node* head) {
       Node* temp=head;
       if(temp->next==NULL){
           delete temp;
           return NULL;
       }
       
       int len=0;
       while(temp){
           len++;
           temp=temp->next;
       }
       temp=head;
       int kth=(len/2)+1;   // delete kth node
       int count=0;
       Node* prev=NULL;
       while(temp){
           count++;
           if(count==kth){
               prev->next=prev->next->next;
               delete temp;
               break;
           }
           prev=temp;
           temp=temp->next;
       }
       
       return head;
       
    }
};