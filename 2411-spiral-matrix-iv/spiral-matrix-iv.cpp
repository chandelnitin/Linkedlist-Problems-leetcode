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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ListNode* temp=head;
        int direction =0;
        int left =0; int right =n-1; int bottom =m-1; int top=0;
        vector<vector<int>> v(m, vector<int>(n, -1));
        while(left<=right && top<=bottom){
            if(direction==0){
                for(int col=left;col<=right;col++){
                    if(temp){
                        v[top][col]=temp->val;
                         temp=temp->next;
                    }
                    else{
                         v[top][col]=-1;
                    }
                    
                }
                top++;
                direction++;
            }
            else if(direction==1){
                for(int row=top;row<=bottom;row++){
                    if(temp){
                        v[row][right]=temp->val;
                        temp=temp->next;
                    }
                    else{
                        v[row][right]=-1;
                    }
                    
                }
                right--;
                direction++;
            }
            else if(direction==2){
                for(int col=right;col>=left;col--){
                    if(temp){
                        v[bottom][col]=temp->val;
                        temp=temp->next;
                    }
                    else{
                         v[bottom][col]=-1;
                    }
                }
                direction++;
                bottom--;
                
            }
            else{
                for(int row=bottom; row>=top;row--){
                    if(temp){
                        v[row][left]=temp->val;
                        temp=temp->next;
                    }
                    else{
                        v[row][left]=-1;
                    }
                    
                }
                left++;
                direction++;
            }

            direction=direction%4;
        }

        return v;
    }
};