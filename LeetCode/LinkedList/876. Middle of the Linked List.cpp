#include <bits/stdc++.h>

using namespace std;

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
    ListNode* middleNode(ListNode* head) {
        /*ListNode* current = head;
        int cnt = 0, mid;
        
        while(current!=NULL){
            cnt++;
            current = current->next;
        }
        //cout<<cnt<<endl;
        mid = cnt/2;
        current = head;
        cnt = 0;
        while(cnt<mid){
            current = current->next;
            cnt++;
        }
        return current;
        */
        //Method 2 : First and Slow pointer
        ListNode* fast = head, *slow = head;
        while(fast!=NULL and fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main(){
	
	
	
	
	return 0;
}

