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
    ListNode* insertionSortList(ListNode* head) {
        
        
        //using extra memory
        /*
        vector<int> nums;
        
        while(head!=NULL){
            nums.push_back(head->val);
            head = head->next;
        }
        
        for(int i=0;i<nums.size();i++){
            int pos = i;
            int tmp = nums[pos];
            
            while(pos>0 and nums[pos-1]>tmp){
                nums[pos] = nums[pos-1];
                pos--;
            }
            nums[pos] = tmp;
        }
        
        
        ListNode start = NULL;
        ListNode* tmp = &start;
        
        for(auto& i: nums){
            tmp->next = new ListNode(i);
            tmp = tmp->next;
        }
        
        return start.next;
        */
        
        //without using any extra space
        ListNode start = NULL;
        ListNode* tmp = &start;
        
        ListNode* curr = head;
        
        while(curr!=NULL){
            ListNode* tmp1 = curr->next;
            
            while(tmp->next!=NULL and tmp->next->val<curr->val){
                tmp = tmp->next;
            }
            //insert between tmp and tmp->next;
            curr->next = tmp->next;
            tmp->next = curr;
            
            //again initializing tmp position to first 
            tmp = &start;
            
            curr = tmp1;
        }
        
        return start.next;
    }
};
