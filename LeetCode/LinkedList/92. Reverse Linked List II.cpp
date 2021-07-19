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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head==NULL) return NULL;
        else if(left==right) return head;
        
        ListNode res(0);
        res.next = head;
        // res->next = head;
        ListNode* slow = &res;
        
        right-=left;
        
        for(int i=1;i<left;i++){
            slow = slow->next;
        }
        
        ListNode* fast = slow->next;
        ListNode* tmp;
        
        
        
        while(right--){
            tmp = fast->next;
            fast->next = fast->next->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        return res.next;
    }
};
