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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode head = NULL;
        ListNode* tmp = &head;
        
        int x;
        int carry = 0;
        
        while(l1!=NULL and l2!=NULL){
            x = l1->val + l2->val + carry;
            
            if(x>9){
                x = x-10;
                carry = 1;
            }
            else carry = 0;
            
            tmp->next = new ListNode(x);
            tmp = tmp->next;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1!=NULL){
            x = l1->val + carry;            
            if(x>9){
                x = x-10;
                carry = 1;
            }
            else carry = 0;
            
            tmp->next = new ListNode(x);
            tmp = tmp->next;
            l1 = l1->next;
        }
        while(l2!=NULL){
            x = l2->val + carry;            
            if(x>9){
                x = x-10;
                carry = 1;
            }
            else carry = 0;
            
            tmp->next = new ListNode(x);
            tmp = tmp->next;
            l2 = l2->next;
        }
        
        if(carry==1) {
            tmp->next = new ListNode(carry);
        }
        
        return head.next;
    }
};
