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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(!head) return head;
        
        ListNode start = NULL;
        ListNode* tmp = &start;
        ListNode* prev = tmp;
        
        ListNode* curr = head;
        while(curr!=NULL){
            ListNode* tail = curr;
            int cnt = 0;

            while(curr!=NULL and cnt<k){
                curr = curr->next;
                cnt++;
            }
            if(cnt==k){
                prev->next = reverse(tail, k);
                prev = tail;
            }
            else {
                prev->next = tail;
            }
        }
        
        
        return start.next;
    }
private:
    ListNode* reverse(ListNode* head, int k){
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr!=NULL and k--){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        head = prev;
        
        return head;
    }
};
