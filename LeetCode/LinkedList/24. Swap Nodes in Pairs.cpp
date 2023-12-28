// 24. Swap Nodes in Pairs
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
        
       ListNode* curr = head;
       int i = 1;

       while(curr and curr->next){
           if(i&1) swap(curr->val, curr->next->val);
           curr = curr->next;
           i++;
       }
       return head;
    }
};