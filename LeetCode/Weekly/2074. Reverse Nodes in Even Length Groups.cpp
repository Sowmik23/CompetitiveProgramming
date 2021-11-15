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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        
        if(head==NULL) return head;
        
        ListNode* curr = head;
        int cnt = 1;
        
        
        ListNode rest = NULL;
        ListNode* res = &rest;
        
        
        res->next = curr;
        res = res->next;
        curr = curr->next;
        
        cnt++;  //now cnt is 2;
        
        ListNode* prev = res;
        
        while(curr!=NULL){
            ListNode* tail = curr;
            
            ListNode tmp1 = NULL;
            ListNode* tmp11 = &tmp1;
            
            int i=1;
            for(i=1;i<=cnt and curr!=NULL;i++){
                //res->next = curr;
                
                tmp11->next = curr;
                tmp11 = tmp11->next;
                //res = res->next;
                curr = curr->next;
            }
         
            if((i-1)%2==0){
                
                
                tmp11->next = NULL;
                ListNode* r = reverse(tmp1.next);
                
                // ListNode* r1 = r;
                // while(r1!=NULL){
                //     cout<<r1->val<<" ";
                //     r1 = r1->next;
                // }
                // cout<<"end reverse"<<endl;
                
                prev->next = r;
                prev = tail;
                
            }
            else {
                
                //tmp11 = tail;
                tmp11->next = NULL;
                
                
                // ListNode* r1 = tmp1.next;
                // while(r1!=NULL){
                //     cout<<r1->val<<" ";
                //     r1 = r1->next;
                // }
                // cout<<" not reverse"<<endl;
                
                prev->next = tmp1.next;
                prev = tmp11;
            }
            
            
            cnt++;
        }
        
        return rest.next;
        
    }
private:
    ListNode* reverse(ListNode* head){
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr!=NULL){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        
        head = prev;
        return head;
    }
};
