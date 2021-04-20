
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
    bool isPalindrome(ListNode* head) {
        
        ListNode* fast = head, *slow = head;
        while(fast->next!=NULL and fast->next->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = reverse(slow->next);
        //cout<<slow->val<<endl;
        while(slow!=NULL){
            if(slow->val!=head->val) return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
    
private:
    ListNode* reverse(ListNode* slow){
        if(slow==NULL or slow->next==NULL) return slow; 
        ListNode* prev = NULL;
        while(slow!=NULL){
            ListNode *new_node = slow->next;
            slow->next = prev;
            prev = slow;
            slow = new_node;
        }
        return prev;
    }
};
