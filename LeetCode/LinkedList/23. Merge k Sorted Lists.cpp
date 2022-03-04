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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        //using extra array and sorting stl function
        //can also be done using priority queue.
        
        int k = lists.size();
        vector<int> mergedArr;
        
        for(int i=0;i<k;i++){
            ListNode* head = lists[i];
            while(head!=NULL){
                mergedArr.push_back(head->val);
                head = head->next;
            }
        }
        
        sort(mergedArr.begin(), mergedArr.end());
        
        ListNode res = NULL;
        ListNode* tmp = &res;
        for(int i=0;i<mergedArr.size();i++){
            tmp->next = new ListNode(mergedArr[i]);
            tmp = tmp->next;
        }
        
        
        return res.next;
    }
};
