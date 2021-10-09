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
    bool hasCycle(ListNode *head) {
        
        
        ///Floyd's cycle finding algorithm: using slow and fast pointer
        
        if(head==NULL) return false;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(slow!=fast){
            
            if(fast==NULL or fast->next==NULL) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
       return true;
    }
};
