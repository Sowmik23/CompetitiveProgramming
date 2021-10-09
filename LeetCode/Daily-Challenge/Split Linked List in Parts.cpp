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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        
        vector<ListNode*> res;
        if(head==NULL){
            res = vector<ListNode*> (k);
            return res;
        } 
        
        ListNode* curr = head;
        
        int cnt = 0;
        while(curr!=NULL){
            cnt++;
            curr = curr->next;
        }
        if(cnt<=k){
            ListNode* curr = head;
            
            while(curr!=NULL){
                ListNode* tmp = new ListNode(curr->val);
                res.push_back(tmp);
                curr = curr->next;
            }
            if(head!=NULL) res.resize(k);
        }
        else {
            int remainder = cnt%k;
        
            ListNode* curr = head;
            
            
            int n = cnt/k;
            if(remainder>0) {
                n++;
                remainder--;
            }
            ListNode tmp = NULL;
            ListNode* tmp_node = &tmp;
            while(curr!=NULL){
                tmp_node->next = curr;
                
                tmp_node = tmp_node->next;
                curr = curr->next;
                n--;
                if(n==0){
                    tmp_node->next = NULL;
                    res.push_back(tmp.next);
                    n = cnt/k;
                    if(remainder>0) {
                        n++;
                        remainder--;
                    }
                    tmp = NULL;
                    tmp_node = &tmp;
                }
            }
            
        }
        
        
        return res;
    }
};
