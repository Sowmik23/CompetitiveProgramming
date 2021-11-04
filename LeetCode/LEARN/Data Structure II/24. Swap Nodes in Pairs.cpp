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
    ListNode* swapPairs(ListNode* head) {
        
        //recursive task
        
        if(head==NULL or head->next==NULL) return head;
        
        ListNode start = NULL;
        ListNode* tmp = &start;
        
        ListNode* curr = head;
        
        while(curr!=NULL and curr->next!=NULL){
            
            ListNode* tmp1 = curr;
            ListNode* tmp2 = curr->next;
            ListNode* tmp3;
            
            if(curr->next->next!=NULL) tmp3 = tmp2->next;
            else tmp3=NULL;
            
          
            tmp->next = tmp2;
            tmp = tmp->next;
            
            
            tmp->next = tmp1;
            tmp = tmp->next;
            
            
            
            if(tmp3==NULL) {
                curr = NULL;
                tmp->next = NULL;
                break;
            }
            else curr = tmp3;
        }
        
        if(curr!=NULL){
            tmp->next = curr;
        }
            
       
        return start.next;
    }
};
