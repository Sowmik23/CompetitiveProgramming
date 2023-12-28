// 725. Split Linked List in Parts
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
        
        //using extra memory
        /*
        queue<ListNode*> q;
        ListNode* tmp = head;
        while(tmp){
            q.push(tmp);
            tmp = tmp->next;
        }
    
        int n = q.size();
        int sz = n/k;
        int extra = n%k;
        vector<ListNode*> res;
        int iteration = k; 

        while(iteration){
            ListNode start = NULL;
            ListNode* curr = &start;
            int cnt = 0;
            while(!q.empty() and n>=k and cnt<sz){
                curr->next = q.front();
                q.pop();
                curr = curr->next;
                cnt++;
            }
            if(extra>0 and !q.empty()){
                curr->next = q.front();
                curr = curr->next;
                q.pop();
                extra--;
            }
            curr->next = NULL;
            res.push_back(start.next);
            iteration--;
        }
        return res;
        */

        //without using extra memory
        int n = 0;
        ListNode* curr = head;
        while(curr){
            n++;
            curr = curr->next;
        }
        int sz = n/k;
        int extra = n%k;
        vector<ListNode*> res;
        curr = head;
        
        while(curr){
            ListNode start = NULL;
            ListNode* tmp = &start;
            int cnt = 0;
            while(curr and cnt<sz){
                tmp->next = curr;
                tmp = tmp->next;
                curr = curr->next;
                cnt++;
            }
            if(curr and extra>0){
                tmp->next = curr;
                tmp = tmp->next;
                curr = curr->next;
                extra--;
            }
            tmp->next = NULL;
            res.push_back(start.next);
            k--;
        }
        while(k>0){
            res.push_back({NULL});
            k--;
        }
        return res;
    }
};