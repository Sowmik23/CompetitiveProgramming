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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode start = NULL;
        ListNode* tmp = &start;
        
        if(head==NULL) return NULL;
        
        ListNode* curr = head;
    
        
        while(curr!=NULL){
            
            if(curr->next!=NULL and curr->val==curr->next->val){    
                while(curr->next!=NULL and curr->val==curr->next->val){
                    curr = curr->next;
                }
                tmp->next = curr->next;
            }
            else {
                tmp->next = curr;
                tmp = tmp->next;    
            }
            
            curr = curr->next;
        }
        
        return start.next;
    }
};
