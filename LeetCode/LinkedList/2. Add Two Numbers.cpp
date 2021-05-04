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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        //ListNode* rl1 = reverse(l1);
        //ListNode* rl2 = reverse(l2);
        
        ListNode* res = NULL;
        ListNode** node = &res;
        
        int sum=0;
        
        while(l1!=NULL or l2!=NULL or sum>0){
         
            if(l1!=NULL){
                sum+=l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2 = l2->next;
            }
            
            (*node) = new ListNode(sum%10);
            sum = sum/10;
            node = &((*node)->next);
        }
        // if(sum>0){
        //     (*node) = new ListNode(sum%10);
        //     sum = sum/10;
        //     node = &((*node)->next);
        // }
           /*
            // cout<<rl1->val<<" "<<rl2->val<<endl;
            
            sum = rl1->val + rl2->val;
            
            (*node) = new ListNode(sum%10);
            sum = sum/10;
            node = &((*node)->next);
            
            rl1 = rl1->next;
            rl2 = rl2->next;
        }
        
        while(rl1!=NULL){
            sum = sum+rl1->val;
            
            (*node) = new ListNode(sum%10);
            sum = sum/10;
            node = &((*node)->next);
            
            rl1 = rl1->next;
        }
        while(rl2!=NULL){
            sum = sum+rl2->val;
            
            (*node) = new ListNode(sum%10);
            sum = sum/10;
            node = &((*node)->next);
            
            rl2 = rl2->next;
        }
        if(sum>0){
            (*node) = new ListNode(sum%10);
            sum = sum/10;
            node = &((*node)->next);
        }
        */
            
        return res;
    }
    
    private:
    ListNode* reverse(ListNode* tmp){
        
        ListNode* prev = NULL;
        
        while(tmp!=NULL){
            ListNode* next_node = tmp->next;
            
                
            tmp->next = prev;
            prev = tmp;
            tmp = next_node;
        }
        
        return prev;
    }
};
