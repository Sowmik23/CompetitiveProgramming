
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* node = NULL;
        ListNode** tmp = &node;
        
        while(l1!=NULL or l2!=NULL){
            if(l1!=NULL and l2!=NULL){
                
                if(l1->val < l2->val){
                    (*tmp) = new ListNode(l1->val);
                    tmp = &((*tmp)->next);
                    
                    l1 = l1->next;
                }
                else 
                {
                    (*tmp) = new ListNode(l2->val);
                    tmp = &((*tmp)->next);
                    
                    l2 = l2->next;
                }
            }
            else if(l1!=NULL){
                (*tmp) = new ListNode(l1->val);
                tmp = &((*tmp)->next);
                
                l1 = l1->next;
            }
            else if(l2!=NULL){
                (*tmp) = new ListNode(l2->val);
                tmp = &((*tmp)->next);
                
                l2 = l2->next;
            }
        }
        
        return node;
    }
};
