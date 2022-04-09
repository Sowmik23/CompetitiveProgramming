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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head) return head;
        
        
        ListNode res = NULL;
        ListNode* tmp = &res;
        
        int cnt = 0;
        ListNode* curr = head;
        
        while(curr!=NULL){
            curr = curr->next;
            cnt++;
        }
        
        k = k%cnt;
        
        if(k==0) return head;
        
        curr = head;
        curr = reverse(curr);
        
        while(k and curr){
           // cout<<curr->val<<" ";
            tmp->next = curr;
            if(k==1){
                head = curr->next;
            }
            tmp = tmp->next;
            curr = curr->next;
            k--;
        }
        tmp->next = NULL;
        
        ListNode* it = res.next;
        
        it = reverse(it);
        
        ListNode ans = NULL;
        tmp = &ans;
        
        while(it!=NULL){
            tmp->next = it;
            it = it->next;
            tmp = tmp->next;
        }
        
        
        head = reverse(head);
        tmp->next = head;
        
        return ans.next;
    }
private:
    ListNode* reverse(ListNode* head){
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* tmp;
        
        while(curr!=NULL){
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            
            curr = tmp;
        }
        
        return prev;
    }
};
