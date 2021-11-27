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
    void reorderList(ListNode* head) {
        
        if(!head or !head->next) return;
        
        int cnt = 0;
        //ListNode* reverseHead = reverse(head, cnt);
        //cout<<cnt<<endl;
        
        stack<ListNode*> stk;
        ListNode* tmp = head;
        while(tmp!=NULL){
            cnt++;
            stk.push(tmp);
            tmp = tmp->next;
        }
        
        ListNode* curr = head;
      
        for(int i=0;i<cnt/2;i++){
//             tmp1 = curr->next;
//             tmp2 = reverseHead->next;

//             curr->next = reverseHead;
//             reverseHead->next = tmp1;

//             reverseHead = tmp2;
//             curr = tmp1->next;   
        
            ListNode* k = stk.top();
            k->next = curr->next;
            stk.pop();
            
            curr->next = k;
            curr = curr->next->next;
        }
        curr->next = NULL;
    }
    
private:
    ListNode* reverse(ListNode* hd, int &cnt){
        ListNode* curr = hd;
        ListNode* prev = NULL;
        
        while(curr!=NULL){
            cnt++;
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        
        return prev;
    }
};
