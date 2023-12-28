// 1721. Swapping Nodes in a Linked List
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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* tmp1 = head, *tmp2 = head;
        ListNode* curr = head;

        for(int i=1;i<k;i++){
            curr = curr->next;
        }

        tmp1 = curr;
        if(curr) curr = curr->next;

        while(curr){
            tmp2 = tmp2->next;
            curr = curr->next;
        }
        swap(tmp1->val, tmp2->val);
        return head;
    }
};