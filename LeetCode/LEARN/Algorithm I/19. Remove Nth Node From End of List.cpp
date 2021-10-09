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
        
        //One approach is to reverse the list and remove the nth node
        
        /*ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr!=NULL){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        
        head = prev;
        curr = prev;
        
        for(int i=1;i<n;i++){
            curr = curr->next;
        }
        
        curr = curr->next->next;
        .
        */
    
        // another approach is two pointer
        
        ListNode* dummy_head = new ListNode();
        dummy_head->next = head;
        
        ListNode* fast = dummy_head;
        ListNode* slow = dummy_head;
        
        for(int i=1;i<=n;i++){
            fast = fast->next;
        }
        
        while(fast->next!=NULL){
            
            slow = slow->next;
            fast = fast->next;
        }
        
        slow->next = slow->next->next;
        
        return dummy_head->next;
    }
};
