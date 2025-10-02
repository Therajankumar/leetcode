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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        
       ListNode* temp =head;
       int l=0;
       while(temp != NULL){
        l++;
        temp =temp->next;
       }
         if (l == n) {
        ListNode* newhead = head->next;
        delete (head);
        return newhead;
    }
       temp=head;
      
       for(int i=0 ;i<(l-n-1);i++){
        
        temp=temp->next;
       }
       ListNode* delnode =temp->next;
       temp->next =temp->next->next;
       delete(delnode);
       return head;
    }
};