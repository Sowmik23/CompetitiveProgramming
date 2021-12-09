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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head==NULL) return head;
        if(head->next==NULL) {
            head = NULL;
            return head; 
        } 
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;
        
        while(fast!=NULL and fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //cout<<prev->val<<" "<<slow->val<<endl;
        prev->next = slow->next;
        
        return head;
    }
};
