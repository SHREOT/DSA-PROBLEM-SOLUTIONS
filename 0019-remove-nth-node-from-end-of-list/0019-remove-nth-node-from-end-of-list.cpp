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
int getlength(ListNode*head){
      ListNode*curr=head;
      int count=0;
      while(curr!=NULL){
          curr=curr->next;
         count++;
      }
      return count;
  }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
           if(getlength(head)==n){
               return head->next;
           }
           
           if(head==NULL){
               return head;
           }
           ListNode*prev=head;
           ListNode*curr=head->next;

           int k =getlength(head)-(n+1);
           while(k!=0){
               curr=curr->next;
               prev=prev->next;
               k--;
           }

           prev->next=curr->next;
           curr->next=NULL;

           return head;
    }
};