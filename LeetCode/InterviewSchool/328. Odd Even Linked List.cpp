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
    ListNode* oddEvenList(ListNode* head) {
        
        ListNode evenList = NULL;
        ListNode* even = &evenList;
        
        ListNode oddList = NULL;
        ListNode* odd = &oddList;
        
        int i= 1;
        while(head!=NULL){
            if(i%2==1){
                odd->next = head;
                odd = odd->next;
            }
            else {
                even->next = head;
                even = even->next;
            }
            head = head->next;
            i++;
        }
        even->next = NULL;
        
        odd->next = evenList.next;
        return oddList.next;
    }
};
