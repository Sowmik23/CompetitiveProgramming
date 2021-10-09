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
        
        ListNode* curr = head;
        ListNode* tmp = head;
        
        for(int i=1;i<=n;i++){
            curr = curr->next;
        }
        
        if(curr==NULL){
            ListNode* res = head->next;
            delete head;
            return res;
        }
        
        while(curr->next!=NULL){
            tmp = tmp->next;
            curr = curr->next;
        }
         
       
        tmp->next = tmp->next->next;
        
        
        return head;
    }
};
