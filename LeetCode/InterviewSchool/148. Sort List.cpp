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
        
        ///MergeSort
        
        if(head==NULL or head->next==NULL){
            return head;
        }
        
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        
        return merge(left, right);
    }
    
private:
    ListNode* getMid(ListNode* head){
        ListNode* midPrev = NULL;
        
        while(head and head->next){
            if(midPrev==NULL){
                midPrev = head;
            }
            else {
                midPrev = midPrev->next;
            }
            
            head = head->next->next;
        }
        
        ListNode* mid = midPrev->next;
        midPrev->next = NULL;
        return mid;
    }
    
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode dummyHead = NULL;
        ListNode* ptr = &dummyHead;
        
        while(list1 and list2){
            if(list1->val < list2->val){
                ptr->next = list1;
                list1 = list1->next;
            }
            else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        if(list1) ptr->next = list1;
        else ptr->next = list2;
        
        return dummyHead.next;
    }
};


//another approach: easier maybe

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
        
        ///MergeSort
        
        if(head==NULL or head->next==NULL){
            return head;
        }
        
        ListNode* tmp = head;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=NULL and fast->next!=NULL){
            tmp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        tmp->next = NULL;
        
        ListNode* left_part = sortList(head);
        ListNode* right_part = sortList(slow);
        
        return merge(left_part, right_part);
    }
    
private:
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode dummyHead = NULL;
        ListNode* ptr = &dummyHead;
        
        while(list1 and list2){
            if(list1->val < list2->val){
                ptr->next = list1;
                list1 = list1->next;
            }
            else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        if(list1) ptr->next = list1;
        else ptr->next = list2;
        
        return dummyHead.next;
    }
};
