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
       /*//iterative
        ListNode* prev = NULL;
        while(head!=NULL){
            ListNode *next_node = head->next;
            head->next = prev;
            prev = head;
            head = next_node;
        }
        return prev;
        */
        
        if(head==NULL) return res;
        ListNode *next_node = head->next;
        head->next = res;
        res = head;
        head = next_node;
        
        reverseList(head);
        
        return res;
    }
};
