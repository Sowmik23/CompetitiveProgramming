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
    int cnt=0, res=0;
    int getDecimalValue(ListNode* head) {
        /*printing the list
        while(head!=NULL){
         cout<<head->val<<endl;
         head = head->next;
        }   
      */
        if(head==NULL) return res;
        getDecimalValue(head->next);
        
        //cout<<head->val<<endl;
        res+= head->val*(pow(2, cnt));
        cnt++;
       // cout<<cnt<<" fdf ";
        return res;
    }
};
