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
    void deleteNode(ListNode* node) {
        
        /*
        The tricky point is that we can not use

            node=node->next
        Because we have not change the address content stored in the previous node.

        In fact , a linked list will be stored like this:

        head ->  {val1,   address2}    {val2, address3}  {val3, address4}   {val4, NULL}
        So, if we are given access to the *cur = {val3, address4}

        If we want to delete the *cur, we have to change the content stored in *cur.

        If we use cur=cur->next, what happens ?

        OOPS ! nothing happens ... because the "address#" stored in the linked list keeps no changing!

        So "cur=cur->next" makes no impact on the linked list.
        */
        
       // *node = *node->next;
    
        //or another way
      /*  ListNode* tmp = node->next;
        *node = *tmp;
        delete tmp;
        */
        
        ///Another way
        node->val= node->next->val; ///as node will never be a tail node as described in problem
        node->next = node->next->next;
    }
};
