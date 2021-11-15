#include <bits/stdc++.h>
using namespace std;


// Time: O(nlogn)
// Space: O(logn)


// Merge Sort is preferred for sorting linkedlist.
// The slow random-access performance of a linked list makes some
// other algorithms(such as quick sort) perform poorly. and others
// (such as heap sort) makes completely impossible.


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
    ListNode* sortList(ListNode* head) {
        
        if(head==NULL or head->next==NULL) return head;
        
        ListNode* tmp = head;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=NULL and fast->next!=NULL){
            tmp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        tmp->next = NULL;
        
        ListNode* leftpart = sortList(head);
        ListNode* rightpart = sortList(slow);
        
        return mergeList(leftpart, rightpart);
    }
    
private:
    ListNode* mergeList(ListNode* a, ListNode* b){
        
        ListNode start = NULL;
        ListNode* tmp = &start;
        
        while(a!=NULL and b!=NULL){
            if(a->val < b->val){
                tmp->next = a;
                a = a->next;
            }
            else {
                tmp->next = b;
                b = b->next;
            }
            tmp = tmp->next;
        }
        if(a!=NULL){
            tmp->next = a;
        }
        if(b!=NULL){
            tmp->next = b;
        }
        
        return start.next;
    }
};


int main(){
	
	
	
	return 0;
}
