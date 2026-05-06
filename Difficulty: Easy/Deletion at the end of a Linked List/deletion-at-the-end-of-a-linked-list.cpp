/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* removeLastNode(Node* head) {
        Node* temp=head;
        if(temp->next==NULL || head==NULL){
            return NULL;
        }
        while(temp->next->next){
            temp=temp->next;
        }
        
        delete temp->next;
        temp->next=NULL;
        return head;
    }
};