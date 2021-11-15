/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL or head->next==NULL) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;
        
        while(fast->next!=NULL and fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow==fast){
                while(slow!=entry){
                    slow = slow->next;
                    entry = entry->next;
                }
                
                return entry;
            }
        }
        
        return NULL;
    }
};
