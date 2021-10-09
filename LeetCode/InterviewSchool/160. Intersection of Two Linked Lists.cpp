/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA==NULL or headB==NULL) return NULL;
        
        ListNode* pathA = headA;
        ListNode* pathB = headB;
        
        while(pathA!=NULL and pathB!=NULL and pathA!=pathB){
            pathA = pathA->next;
            pathB = pathB->next;
            
            if(pathA==pathB) return pathA;
            
            if(pathA==NULL) pathA = headB;
            if(pathB==NULL) pathB = headA;
        }
        
        return pathA;
    }
};
