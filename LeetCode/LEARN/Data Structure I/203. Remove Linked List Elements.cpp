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
    ListNode* removeElements(ListNode* head, int val) {
      
        ///Approach-01: Hard to think about pointers
      /*
      if(head==NULL) return head;
        
        if(head->next==NULL){
            if(head->val==val) return NULL;
        }
        
        // ListNode* curr_head = head;
        // ListNode** curr = &curr_head;
        
        //or
        ListNode** curr = &head;
        
        
        while(*curr!=NULL){
           if((*curr)->val==val){
               (*curr) = (*curr)->next;
           }
            else curr = &(*curr)->next;
        }
        
        return head;
        */
        
        ///Approach-02: Simple way
        
        ListNode* tmp = head;
        while(tmp!=NULL and tmp->next!=NULL){
            if(tmp->next->val==val){
                tmp->next = tmp->next->next;
            }
            else tmp = tmp->next;
        }
        
        while(head!=NULL and head->val==val){
            head = head->next;
        }
        
        return head;
    }
};
