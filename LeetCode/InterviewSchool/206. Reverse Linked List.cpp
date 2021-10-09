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
    ListNode* res = NULL;
    ListNode* reverseList(ListNode* head) {
        
        ///iterative version
     /*   ListNode* prev =  NULL;
        
        while(head!=NULL){
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp; 
        }
        return prev;
        */
        
        ///recursive version
        
        if(head==NULL) return res;
        ListNode* tmp = head->next;
        head->next = res;
        res = head;
        head = tmp;
        
        reverseList(head);
        
        return res;
    }
};
