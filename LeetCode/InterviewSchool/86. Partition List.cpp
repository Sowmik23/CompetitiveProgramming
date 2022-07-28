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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode start = NULL;
        ListNode* tmp = &start;
        
        ListNode snd = NULL;
        ListNode* stmp = &snd;
        
        while(head!=NULL){
            if(head->val<x){
                tmp->next = head;
                tmp = tmp->next;
            }
            else {
                stmp->next = head;
                stmp = stmp->next;
            }
            head = head->next;
        }
        
        stmp->next = NULL;
        tmp->next = snd.next;

        //cout<<start.next->val<<" "<<snd.next->val<<endl;
        
        return start.next;
    }
};





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
    ListNode* partition(ListNode* head, int x) {
     
        ListNode left_part = NULL;
        ListNode* left = &left_part;
        
        ListNode right_part = NULL;
        ListNode* right = &right_part;
        
        
        while(head!=NULL){
            if(head->val<x){
                left->next = head;
                left = left->next;
            }
            else {
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }
        
        right->next = NULL;
        
        left->next = right_part.next;
        
        return left_part.next;
    }
};
