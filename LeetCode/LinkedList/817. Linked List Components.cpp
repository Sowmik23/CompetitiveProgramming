// 817. Linked List Components
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
    int numComponents(ListNode* head, vector<int>& nums) {
        
        int cnt = 0;
        unordered_map<int, bool> mp;
        for(auto& num: nums) mp[num] = true;

        int flag = false;
        while(head){
            int val = head->val;
            if(mp.find(val)!=mp.end()){
                flag = true;
            }
            else {
                if(flag) cnt++;
                flag = false;
            }
            head = head->next;
        }
        if(flag) cnt++;
        return cnt;
    }
};