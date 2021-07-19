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
        
        if(head==NULL or k==1) return head; 
        
        ListNode* root = new ListNode(-1);

        ListNode* curr = head;
        ListNode* prev = root;
        
        
        while(curr!=NULL){
            ListNode* tail = curr;
            int cnt = 0;
            
            while(curr!=NULL and cnt<k){
                curr = curr->next;
                cnt++;
            }
            if(cnt==k){
                prev->next = reverse(tail, k); //assign prev to tail  
                prev = tail; //update prev
            }
            else {
                prev->next = tail;
            }
        }
        
        return root->next;
    }
    
    
private:
    ListNode* reverse(ListNode* head, int k){
//      NULL      1      2    3      4       5 
//       prev     curr  tmp
                    
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* tmp;
        
        while(curr!=NULL and k--){
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        head = prev;
        return head;
    }
};
