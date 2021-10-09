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
        
        ///Using extra space
        ListNode res=NULL;
        ListNode* curr = &res;
        while(l1!=NULL and l2!=NULL){
            
            if(l1->val < l2->val){
                // ListNode** tmp = &l1;
                // curr->next = *tmp;
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                // ListNode** tmp = &l2;
                // curr->next = *tmp;
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        // while(l1!=NULL){
        //     curr->next = l1;
        //     l1 = l1->next;
        //     curr = curr->next;
        // }
        // while(l2!=NULL){
        //     curr->next = l2;
        //     l2 = l2->next;     
        //     curr = curr->next;
        // }
        
        ///above two while loop can be written as: 
        if(l1!=NULL){
            curr->next = l1;
        }
        else {
            curr->next = l2;
        }
        
        return res.next;
    }
};
